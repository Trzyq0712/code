import subprocess as sp
import sys 
import os

if len(sys.argv) < 4:
    raise Exception('Provide with arguments: [generator] [solution] [brute_force] ([num_of_tests])')

tests = int(sys.argv[4]) if len(sys.argv) == 5 else 100
assert 1 <= tests

for fl in sys.argv[1:4]:
    if fl not in os.listdir():
        raise Exception('ERROR: ' + fl + ' not found')

gen = sys.argv[1]
solution = sys.argv[2]
brute = sys.argv[3]


for fl in gen, solution, brute:
    name, ext = os.path.splitext(fl)
    # print(name, ext)
    if ext != '.cpp':
        print(fl, 'is not compilable')
        continue
    try:
        sp.run('g++ ' + fl + ' -static -O2 -o ' + name, check=True, shell=True, stdout=sp.PIPE, stderr=sp.PIPE)
        print(fl, 'compiled succesfully')
    except:
        raise Exception(fl, 'Failed to compile')


def progressBar(current, total):
    barWidth = 30
    percent = current / total * 100
    blocks = int(barWidth * current / total)
    # print(blocks)
    lenInfo = len(str(current) + ' / ' + str(total))
    print('\rProgress: %i / %i %s [%s] %.1f %s Complete'\
        %(current, total, (10 - lenInfo) * ' ', blocks * '█' + (barWidth - blocks) * '-', percent, '%'), end='')
    
def execute(fl):
    fileName, ext = os.path.splitext(fl)
    command = 'python3 ' + fileName + ext if ext == '.py' else './' + fileName
    return command

def compareOutput(file1, file2):
    lines1 = []
    lines2 = []
    with open(file1) as f1:
        lines1 = f1.readlines()
    with open(file2) as f2:
        lines2 = f2.readlines()
    if len(lines1) != len(lines2):
        return 'Output is of different length'
    for ind, (l1, l2) in enumerate(zip(lines1, lines2)):
        if l1 != l2:
            if len(l1) > 30:
                l1 = l1[:30] + '...'
            if len(l2) > 30:
                l2 = l2[:30] + '...'
            return '\nWRONG ANSWER at line {}\nExpected: {}\nGot: {}\n'.format(ind + 1, l1.rstrip(), l2.rstrip())
    return True

agree = ['yes', 'ye', 'y', '', 'yeah']

print()
for i in range(tests):
    sp.run(execute(gen) + ' > test.in', shell=True)
    sp.run(execute(solution) + ' < test.in > solve.out', shell=True)
    sp.run(execute(brute) + ' < test.in > brute.out', shell=True)
    # print('\rTEST', i + 1, end=' ')
    progressBar(i + 1, tests)
    res = compareOutput('brute.out', 'solve.out')
    if res != True:
        print('\nTest case {} FAILED'.format(i + 1))
        print(res)
        displayTest = input('Do you want to review the test case? [yes / no] ')
        if displayTest in agree:
            sp.run('cat test.in', shell=True)
            exit()
        else:
            exit()

print("\nNo bugs have been found!")