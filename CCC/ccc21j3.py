prev_dir = None
while (s := input()) != '99999':
    assert len(s) == 5
    su = int(s[0]) + int(s[1])
    if su % 2 == 1:
        prev_dir = 'left'
    elif su % 2 == 0 and su > 0:
        prev_dir = 'right'
    else:
        assert prev_dir
    print(prev_dir, s[2:])
