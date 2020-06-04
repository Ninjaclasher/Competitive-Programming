import sys
from collections import defaultdict
from operator import itemgetter

class IDKException(Exception):
    pass

class MaybeException(Exception):
    pass

class FuckYouException(Exception):
    pass

class Action:
    def __init__(self, predicate, obj, time=None):
        self.predicate = predicate
        self.obj = obj
        self.time = time

    def __eq__(self, ot):
        return self.predicate == ot.predicate and self.obj == ot.obj

class Solve:
    def __init__(self):
        self.ALWAYS_TRUE = []
        self.ALWAYS_FALSE = []
        self.POSITIVE = defaultdict(list)
        self.NEGATIVE = defaultdict(list)
        self.TIME = 0

    def cur_time(self):
        self.TIME += 1
        return self.TIME

    def negation(self, subject):
        if subject in ["I", "you"]:
            return "don't"
        else:
            return "doesn't"

    def switch_subject(self, subject):
        if subject == "I":
            return "you"
        elif subject == "you":
            return "I"
        return subject

    def format_predicate(self, subject, predicate, pos=True):
        if subject not in ["I", "you"] and pos:
            predicate += "s"
        return predicate

    def format_object(self, obj):
        if obj == "":
            return ""
        return " " + obj

    def format_list(self, lis, last_sep=" and "):
        if len(lis) == 1:
            return lis[0]
        return ", ".join(lis[:-1]) + last_sep + lis[-1]

    def handle_statement(self, tokens):
        subject = tokens.pop(0)
        NEG = (tokens[0] == self.negation(subject))
        if NEG:
            tokens.pop(0)
        predicate = tokens.pop(0)
        if subject not in ["I", "you"] and not NEG:
            predicate = predicate[:-1]
        obj = " ".join(tokens)

        action = Action(predicate, obj, self.cur_time())

        if subject == "everybody":
            if action in self.ALWAYS_FALSE:
                raise FuckYouException
            for actions in self.NEGATIVE.values():
                if action in actions:
                    raise FuckYouException
            self.ALWAYS_TRUE.append(action)
        elif subject == "nobody":
            if action in self.ALWAYS_TRUE:
                raise FuckYouException
            for actions in self.POSITIVE.values():
                if action in actions:
                    raise FuckYouException
            self.ALWAYS_FALSE.append(action)
        else: 
            if NEG:
                if action in self.ALWAYS_TRUE:
                    raise FuckYouException
                if action in self.POSITIVE[subject]:
                    raise FuckYouException
                self.NEGATIVE[subject].append(action)
            else:
                if action in self.ALWAYS_FALSE:
                    raise FuckYouException
                if action in self.NEGATIVE[subject]:
                    raise FuckYouException
                self.POSITIVE[subject].append(action)
    
    def handle_do_question(self, tokens):
        subject = tokens.pop(0)
        predicate = tokens.pop(0)
        obj = " ".join(tokens)
        action = Action(predicate, obj)

        IN_SUB_TRUE = action in self.POSITIVE[subject] or action in self.ALWAYS_TRUE
        IN_SUB_FALSE = action in self.NEGATIVE[subject] or action in self.ALWAYS_FALSE

        if IN_SUB_FALSE and IN_SUB_TRUE:
            raise FuckYouException
        elif not IN_SUB_FALSE and not IN_SUB_TRUE:
            raise MaybeException
        ret = self.format_predicate(subject, predicate, not IN_SUB_FALSE) + self.format_object(obj)
        if IN_SUB_FALSE:
            return "no, " + self.switch_subject(subject) + " " + self.negation(subject) + " " + ret
        else:
            return "yes, " + self.switch_subject(subject) + " " + ret

    def handle_who_question(self, tokens):
        predicate = tokens.pop(0)[:-1]
        obj = " ".join(tokens)
        action = Action(predicate, obj)
        
        IN_EVERYBODY = action in self.ALWAYS_TRUE
        IN_NOBODY = action in self.ALWAYS_FALSE
        
        if IN_EVERYBODY and IN_NOBODY:
            raise FuckYouException
        elif IN_EVERYBODY:
            return "everybody {}s{}".format(predicate, self.format_object(obj))
        
        subjects = []
        for subject, actions in self.POSITIVE.items():
            for act in actions:
                if act == action:
                    subjects.append((act.time, subject))
                    if IN_NOBODY:
                        raise FuckYouException

        subjects.sort()
        subjects = list(map(itemgetter(1), subjects))

        if IN_NOBODY:
            return "nobody {}s{}".format(predicate, self.format_object(obj))
        if len(subjects) == 0:
            raise IDKException

        subjects = list(map(self.switch_subject, subjects))

        if len(subjects) == 1:
            predicate = self.format_predicate(subjects[0], predicate)
        
        return self.format_list(subjects) + " " + predicate + self.format_object(obj)

    def handle_what_question(self, tokens):
        subject = tokens[1]
        actions = []
        for x in self.ALWAYS_TRUE:
            actions.append((x, True))
        for x in self.ALWAYS_FALSE:
            actions.append((x, False))
        for x in self.POSITIVE[subject]:
            actions.append((x, True))
        for x in self.NEGATIVE[subject]:
            actions.append((x, False))

        has_already = []
        actions.sort(key=lambda x: x[0].time)
        ret = []
        for action, pos in actions:
            fin = self.format_predicate(subject, action.predicate, pos) + self.format_object(action.obj)
            if fin in has_already:
                continue
            has_already.append(fin)
            if not pos:
                fin = self.negation(subject) + " " + fin
            ret.append(fin)
        if len(ret) == 0:
            raise IDKException
        return self.switch_subject(subject) + " " + self.format_list(ret, last_sep=", and ")


    def handle_question(self, tokens):
        question_type = tokens.pop(0)
        handler = None
        if question_type in ["do", "does"]:
            handler = self.handle_do_question
        elif question_type == "who":
            handler = self.handle_who_question
        elif question_type == "what":
            handler = self.handle_what_question
        else:
            assert False
        print(handler(tokens) + ".")

    def solve(self):
        CONTRADICTION = False
        while True:
            complete_line = line = input().strip()
            last_char = line[-1]
            line = line[:-1]
            if last_char == '!':
                print(complete_line)
                print()
                return
            elif last_char == '.':
                try:
                    self.handle_statement(line.split())
                except FuckYouException:
                    CONTRADICTION = True
            elif last_char == '?':
                print(complete_line)
                try:
                    if CONTRADICTION:
                        raise FuckYouException
                    self.handle_question(line.split())
                except IDKException:
                    print("I don't know.")
                except MaybeException:
                    print("maybe.")
                except FuckYouException:
                    assert CONTRADICTION
                    print("I am abroad.")
                print()
            else:
                assert False

t = int(input())
for case in range(t):
    print("Dialogue #{}:".format(case+1))
    Solve().solve()
