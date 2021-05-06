from dis import Bytecode
source = 'call(a[b][c] // d,     noo)'
bytecode = compile(source, '<test>', 'exec')

for counter, instruction in enumerate(Bytecode(bytecode)):
    start, end = bytecode.co_cnotab[counter * 2], bytecode.co_cnotab[counter * 2 + 1]
    if start == 0:
        print(instruction.opname, 'too long')
        continue
    if end == 0:
        print(instruction.opname, 'whole line', source)

    start -= 1
    end -= 1
    print(instruction.opname, f'start: {start}, end: {end}', source[start:end])
