'''
def foo():
    x = 10
    y = x*2
    def magic(n):
        n = 0
        print 'magic'
    magic(y)

def ff(n):
    print (n)
    print 'fake magic'

a = foo.__code__
for x in a.co_consts:
    print (x)
import inspect
print(inspect.getdoc(foo.__code__))
for x in inspect.getmembers(foo.__code__):
    print x
print [type(x) for x in a.co_consts]
print tuple([ff.__code__ if type(a) == type(x) else x for x in a.co_consts])

cc = type(a)(a.co_argcount, #int
             a.co_nlocals, #int
             a.co_stacksize, #int
             a.co_flags, #int  
             a.co_code, #str 
             tuple([ff.__code__ if type(x) == type(a) else x for x in a.co_consts]), 
             a.co_names, #tuple
             a.co_varnames, #tuple
             a.co_filename, #str
             a.co_name, #str
             a.co_firstlineno, #int
             a.co_lnotab, #str
             a.co_freevars, #tuple
             a.co_cellvars, #tuple
             )
type(lambda x : x)(cc, foo.func_globals)()
'''
def ff(n):
    print (n)
a = foo.__code__
cc = type(a)(a.co_argcount, #int
             a.co_nlocals, #int
             a.co_stacksize, #int
             a.co_flags, #int  
             a.co_code, #str 
             tuple([ff.__code__ if type(x) == type(a) else x for x in a.co_consts]), 
             a.co_names, #tuple
             a.co_varnames, #tuple
             a.co_filename, #str
             a.co_name, #str
             a.co_firstlineno, #int
             a.co_lnotab, #str
             a.co_freevars, #tuple
             a.co_cellvars, #tuple
             )
type(lambda x : x)(cc, foo.func_globals)()
