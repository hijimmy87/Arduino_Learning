import re


def processNote(note, L=0.25):
    n = [0, L]
    p = ord(note[1])
    if p < 72:
        n[0] = [69, 71, 60, 62, 64, 65, 67][p-65]
    elif p < 104:
        n[0] = [81, 83, 72, 74, 76, 77, 79][p-97]
    if p == 70 or p == 102:
        n[0] += 1
    if note[0]:
        n[0] += [-1, 1][note[0] == '^']
    if note[2]:
        n[0] += [-12, 12][note[2] == '`'] * len(note[2])
    if note[3]:
        n[1] *= int(note[3])
    if note[4]:
        n[1] /= int(note[4])
    return tuple(n)


def processSheet(sheet, L=0.25):
    s = re.findall(r'([_^])?([A-Za-z])([,`]*)(\d*)(?:/(\d*))?', sheet)
    s = [processNote(n, L) for n in s]
    return s


sheets = [
    """
DBAG  D4  | DBAG  E4  | EcBA  F4  | ddcA  B4  |
DBAG  D4  | DBAG  E4  | EcBA  dddd  | edcA  G2  d2 |
BB  B2  BB  B2  | BdGA    B2  z2  | cccc    cBBB    | BAAB    A2  d2  |
BB  B2  BB  B2  | BdGA    B2  z2  | cccc    cBBB    | ddcA    G4 |]""",
    """
G,zzz G,4 | G,zzz G,4 | G,zzz A,4 | A,zzz B,4 |
G,zzz G,4 | G,zzz G,4 | G,zzz A,zzz | A,zzz B,2 z2 |
G,z D,2 G,z D,2 | G,z D,z G,2 D,2 | G,z E,z G,z D,z | E,z D,z F,2 D,2 |
G,z D,2 G,z D,2 | G,z D,z G,2 D,2 | G,z E,z G,z D,z | E,z D,z G,4      |]""",
    """
B,zzz B,4 | B,zzz C4  | Czzz  D4  | Dzzz  D4  |
B,zzz B,4 | B,zzz C4  | Czzz  Dzzz  | Dzzz  D2  z2 |
B,z z2  B,z z2  | B,z zz  B,2 z2  | C,z zz  B,z zz  | A,z zz  A,2 z2  |
B,z z2  B,z z2  | B,z zz  B,2 z2  | C,z zz  B,z zz  | A,z zz  B,4      |]""",
]
durations = []

for i in range(len(sheets)):
    sheets[i], durations = zip(*processSheet(sheets[i], 0.125))
    print(f'{len(sheets[i])} B.{i+1} =', sheets[i])
    print()
print('durations =', durations)
