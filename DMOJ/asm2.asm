.section .data
    a: .long 0
    b: .long 0
    c: .long 0
    d: .long 0
    val: .long 0
    num: .long 0
    b100: .long 0
    b99: .long 0
    b98: .long 0
    b97: .long 0
    b96: .long 0
    b95: .long 0
    b94: .long 0
    b93: .long 0
    b92: .long 0
    b91: .long 0
    b90: .long 0
    b89: .long 0
    b88: .long 0
    b87: .long 0
    b86: .long 0
    b85: .long 0
    b84: .long 0
    b83: .long 0
    b82: .long 0
    b81: .long 0
    b80: .long 0
    b79: .long 0
    b78: .long 0
    b77: .long 0
    b76: .long 0
    b75: .long 0
    b74: .long 0
    b73: .long 0
    b72: .long 0
    b71: .long 0
    b70: .long 0
    b69: .long 0
    b68: .long 0
    b67: .long 0
    b66: .long 0
    b65: .long 0
    b64: .long 0
    b63: .long 0
    b62: .long 0
    b61: .long 0
    b60: .long 0
    b59: .long 0
    b58: .long 0
    b57: .long 0
    b56: .long 0
    b55: .long 0
    b54: .long 0
    b53: .long 0
    b52: .long 0
    b51: .long 0
    b50: .long 0
    b49: .long 0
    b48: .long 0
    b47: .long 0
    b46: .long 0
    b45: .long 0
    b44: .long 0
    b43: .long 0
    b42: .long 0
    b41: .long 0
    b40: .long 0
    b39: .long 0
    b38: .long 0
    b37: .long 0
    b36: .long 0
    b35: .long 0
    b34: .long 0
    b33: .long 0
    b32: .long 0
    b31: .long 0
    b30: .long 0
    b29: .long 0
    b28: .long 0
    b27: .long 0
    b26: .long 0
    b25: .long 0
    b24: .long 0
    b23: .long 0
    b22: .long 0
    b21: .long 0
    b20: .long 0
    b19: .long 0
    b18: .long 0
    b17: .long 0
    b16: .long 0
    b15: .long 0
    b14: .long 0
    b13: .long 0
    b12: .long 0
    b11: .long 0
    b10: .long 0
    b9: .long 0
    b8: .long 0
    b7: .long 0
    b6: .long 0
    b5: .long 0
    b4: .long 0
    b3: .long 0
    b2: .long 0
    b1: .long 0
    a0: .long 0
    a1: .long 0
    a2: .long 0
    a3: .long 0
    a4: .long 0
    a5: .long 0
    a6: .long 0
    a7: .long 0
    a8: .long 0
    a9: .long 0
    a10: .long 0
    a11: .long 0
    a12: .long 0
    a13: .long 0
    a14: .long 0
    a15: .long 0
    a16: .long 0
    a17: .long 0
    a18: .long 0
    a19: .long 0
    a20: .long 0
    a21: .long 0
    a22: .long 0
    a23: .long 0
    a24: .long 0
    a25: .long 0
    a26: .long 0
    a27: .long 0
    a28: .long 0
    a29: .long 0
    a30: .long 0
    a31: .long 0
    a32: .long 0
    a33: .long 0
    a34: .long 0
    a35: .long 0
    a36: .long 0
    a37: .long 0
    a38: .long 0
    a39: .long 0
    a40: .long 0
    a41: .long 0
    a42: .long 0
    a43: .long 0
    a44: .long 0
    a45: .long 0
    a46: .long 0
    a47: .long 0
    a48: .long 0
    a49: .long 0
    a50: .long 0
    a51: .long 0
    a52: .long 0
    a53: .long 0
    a54: .long 0
    a55: .long 0
    a56: .long 0
    a57: .long 0
    a58: .long 0
    a59: .long 0
    a60: .long 0
    a61: .long 0
    a62: .long 0
    a63: .long 0
    a64: .long 0
    a65: .long 0
    a66: .long 0
    a67: .long 0
    a68: .long 0
    a69: .long 0
    a70: .long 0
    a71: .long 0
    a72: .long 0
    a73: .long 0
    a74: .long 0
    a75: .long 0
    a76: .long 0
    a77: .long 0
    a78: .long 0
    a79: .long 0
    a80: .long 0
    a81: .long 0
    a82: .long 0
    a83: .long 0
    a84: .long 0
    a85: .long 0
    a86: .long 0
    a87: .long 0
    a88: .long 0
    a89: .long 0
    a90: .long 0
    a91: .long 0
    a92: .long 0
    a93: .long 0
    a94: .long 0
    a95: .long 0
    a96: .long 0
    a97: .long 0
    a98: .long 0
    a99: .long 0
    a100: .long 0
.globl _start
_start:

    movl $10, %esi
while:
    movl $3, %eax
    xor %ebx, %ebx
    movl $b, %ecx
    movl $1, %edx
    int $0x80
    cmp $10, b
    je continue
    cmp $32, b
    je continue

    movl a, %eax
    mull %esi
    movl %eax, a
    movl $1, %edx
    sub $48, b
    movl b, %ecx
    add %ecx, a
jmp while

continue:
    movl $0, d
    xor %edi, %edi
    while2:
        movl $3, %eax
        xor %ebx, %ebx
        movl $b, %ecx
        movl $1, %edx
        int $0x80
        cmp $10, b
        je continue2
        cmp $32, b
        je continue2
        cmp $45, b
        jne skip
            movl $1, %edi
            jmp while2
        skip:
        movl d, %eax
        mull %esi
        movl %eax, d
        sub $48, b
        movl b, %ecx
        add %ecx, d
    jmp while2
    continue2:
    cmp $1, %edi
    jne skip2
        movl d, %eax
        movl $2, %edi
        mull %edi
        sub %eax, d
    skip2:
    jmp func1
    return1:
    sub $1, a
    cmp $0, a
jnz continue

movl b100, %eax
cmp %eax, num
jge n200
    movl $-100, val
    movl %eax, num
n200:
movl b99, %eax
cmp %eax, num
jge n199
    movl $-99, val
    movl %eax, num
n199:
movl b98, %eax
cmp %eax, num
jge n198
    movl $-98, val
    movl %eax, num
n198:
movl b97, %eax
cmp %eax, num
jge n197
    movl $-97, val
    movl %eax, num
n197:
movl b96, %eax
cmp %eax, num
jge n196
    movl $-96, val
    movl %eax, num
n196:
movl b95, %eax
cmp %eax, num
jge n195
    movl $-95, val
    movl %eax, num
n195:
movl b94, %eax
cmp %eax, num
jge n194
    movl $-94, val
    movl %eax, num
n194:
movl b93, %eax
cmp %eax, num
jge n193
    movl $-93, val
    movl %eax, num
n193:
movl b92, %eax
cmp %eax, num
jge n192
    movl $-92, val
    movl %eax, num
n192:
movl b91, %eax
cmp %eax, num
jge n191
    movl $-91, val
    movl %eax, num
n191:
movl b90, %eax
cmp %eax, num
jge n190
    movl $-90, val
    movl %eax, num
n190:
movl b89, %eax
cmp %eax, num
jge n189
    movl $-89, val
    movl %eax, num
n189:
movl b88, %eax
cmp %eax, num
jge n188
    movl $-88, val
    movl %eax, num
n188:
movl b87, %eax
cmp %eax, num
jge n187
    movl $-87, val
    movl %eax, num
n187:
movl b86, %eax
cmp %eax, num
jge n186
    movl $-86, val
    movl %eax, num
n186:
movl b85, %eax
cmp %eax, num
jge n185
    movl $-85, val
    movl %eax, num
n185:
movl b84, %eax
cmp %eax, num
jge n184
    movl $-84, val
    movl %eax, num
n184:
movl b83, %eax
cmp %eax, num
jge n183
    movl $-83, val
    movl %eax, num
n183:
movl b82, %eax
cmp %eax, num
jge n182
    movl $-82, val
    movl %eax, num
n182:
movl b81, %eax
cmp %eax, num
jge n181
    movl $-81, val
    movl %eax, num
n181:
movl b80, %eax
cmp %eax, num
jge n180
    movl $-80, val
    movl %eax, num
n180:
movl b79, %eax
cmp %eax, num
jge n179
    movl $-79, val
    movl %eax, num
n179:
movl b78, %eax
cmp %eax, num
jge n178
    movl $-78, val
    movl %eax, num
n178:
movl b77, %eax
cmp %eax, num
jge n177
    movl $-77, val
    movl %eax, num
n177:
movl b76, %eax
cmp %eax, num
jge n176
    movl $-76, val
    movl %eax, num
n176:
movl b75, %eax
cmp %eax, num
jge n175
    movl $-75, val
    movl %eax, num
n175:
movl b74, %eax
cmp %eax, num
jge n174
    movl $-74, val
    movl %eax, num
n174:
movl b73, %eax
cmp %eax, num
jge n173
    movl $-73, val
    movl %eax, num
n173:
movl b72, %eax
cmp %eax, num
jge n172
    movl $-72, val
    movl %eax, num
n172:
movl b71, %eax
cmp %eax, num
jge n171
    movl $-71, val
    movl %eax, num
n171:
movl b70, %eax
cmp %eax, num
jge n170
    movl $-70, val
    movl %eax, num
n170:
movl b69, %eax
cmp %eax, num
jge n169
    movl $-69, val
    movl %eax, num
n169:
movl b68, %eax
cmp %eax, num
jge n168
    movl $-68, val
    movl %eax, num
n168:
movl b67, %eax
cmp %eax, num
jge n167
    movl $-67, val
    movl %eax, num
n167:
movl b66, %eax
cmp %eax, num
jge n166
    movl $-66, val
    movl %eax, num
n166:
movl b65, %eax
cmp %eax, num
jge n165
    movl $-65, val
    movl %eax, num
n165:
movl b64, %eax
cmp %eax, num
jge n164
    movl $-64, val
    movl %eax, num
n164:
movl b63, %eax
cmp %eax, num
jge n163
    movl $-63, val
    movl %eax, num
n163:
movl b62, %eax
cmp %eax, num
jge n162
    movl $-62, val
    movl %eax, num
n162:
movl b61, %eax
cmp %eax, num
jge n161
    movl $-61, val
    movl %eax, num
n161:
movl b60, %eax
cmp %eax, num
jge n160
    movl $-60, val
    movl %eax, num
n160:
movl b59, %eax
cmp %eax, num
jge n159
    movl $-59, val
    movl %eax, num
n159:
movl b58, %eax
cmp %eax, num
jge n158
    movl $-58, val
    movl %eax, num
n158:
movl b57, %eax
cmp %eax, num
jge n157
    movl $-57, val
    movl %eax, num
n157:
movl b56, %eax
cmp %eax, num
jge n156
    movl $-56, val
    movl %eax, num
n156:
movl b55, %eax
cmp %eax, num
jge n155
    movl $-55, val
    movl %eax, num
n155:
movl b54, %eax
cmp %eax, num
jge n154
    movl $-54, val
    movl %eax, num
n154:
movl b53, %eax
cmp %eax, num
jge n153
    movl $-53, val
    movl %eax, num
n153:
movl b52, %eax
cmp %eax, num
jge n152
    movl $-52, val
    movl %eax, num
n152:
movl b51, %eax
cmp %eax, num
jge n151
    movl $-51, val
    movl %eax, num
n151:
movl b50, %eax
cmp %eax, num
jge n150
    movl $-50, val
    movl %eax, num
n150:
movl b49, %eax
cmp %eax, num
jge n149
    movl $-49, val
    movl %eax, num
n149:
movl b48, %eax
cmp %eax, num
jge n148
    movl $-48, val
    movl %eax, num
n148:
movl b47, %eax
cmp %eax, num
jge n147
    movl $-47, val
    movl %eax, num
n147:
movl b46, %eax
cmp %eax, num
jge n146
    movl $-46, val
    movl %eax, num
n146:
movl b45, %eax
cmp %eax, num
jge n145
    movl $-45, val
    movl %eax, num
n145:
movl b44, %eax
cmp %eax, num
jge n144
    movl $-44, val
    movl %eax, num
n144:
movl b43, %eax
cmp %eax, num
jge n143
    movl $-43, val
    movl %eax, num
n143:
movl b42, %eax
cmp %eax, num
jge n142
    movl $-42, val
    movl %eax, num
n142:
movl b41, %eax
cmp %eax, num
jge n141
    movl $-41, val
    movl %eax, num
n141:
movl b40, %eax
cmp %eax, num
jge n140
    movl $-40, val
    movl %eax, num
n140:
movl b39, %eax
cmp %eax, num
jge n139
    movl $-39, val
    movl %eax, num
n139:
movl b38, %eax
cmp %eax, num
jge n138
    movl $-38, val
    movl %eax, num
n138:
movl b37, %eax
cmp %eax, num
jge n137
    movl $-37, val
    movl %eax, num
n137:
movl b36, %eax
cmp %eax, num
jge n136
    movl $-36, val
    movl %eax, num
n136:
movl b35, %eax
cmp %eax, num
jge n135
    movl $-35, val
    movl %eax, num
n135:
movl b34, %eax
cmp %eax, num
jge n134
    movl $-34, val
    movl %eax, num
n134:
movl b33, %eax
cmp %eax, num
jge n133
    movl $-33, val
    movl %eax, num
n133:
movl b32, %eax
cmp %eax, num
jge n132
    movl $-32, val
    movl %eax, num
n132:
movl b31, %eax
cmp %eax, num
jge n131
    movl $-31, val
    movl %eax, num
n131:
movl b30, %eax
cmp %eax, num
jge n130
    movl $-30, val
    movl %eax, num
n130:
movl b29, %eax
cmp %eax, num
jge n129
    movl $-29, val
    movl %eax, num
n129:
movl b28, %eax
cmp %eax, num
jge n128
    movl $-28, val
    movl %eax, num
n128:
movl b27, %eax
cmp %eax, num
jge n127
    movl $-27, val
    movl %eax, num
n127:
movl b26, %eax
cmp %eax, num
jge n126
    movl $-26, val
    movl %eax, num
n126:
movl b25, %eax
cmp %eax, num
jge n125
    movl $-25, val
    movl %eax, num
n125:
movl b24, %eax
cmp %eax, num
jge n124
    movl $-24, val
    movl %eax, num
n124:
movl b23, %eax
cmp %eax, num
jge n123
    movl $-23, val
    movl %eax, num
n123:
movl b22, %eax
cmp %eax, num
jge n122
    movl $-22, val
    movl %eax, num
n122:
movl b21, %eax
cmp %eax, num
jge n121
    movl $-21, val
    movl %eax, num
n121:
movl b20, %eax
cmp %eax, num
jge n120
    movl $-20, val
    movl %eax, num
n120:
movl b19, %eax
cmp %eax, num
jge n119
    movl $-19, val
    movl %eax, num
n119:
movl b18, %eax
cmp %eax, num
jge n118
    movl $-18, val
    movl %eax, num
n118:
movl b17, %eax
cmp %eax, num
jge n117
    movl $-17, val
    movl %eax, num
n117:
movl b16, %eax
cmp %eax, num
jge n116
    movl $-16, val
    movl %eax, num
n116:
movl b15, %eax
cmp %eax, num
jge n115
    movl $-15, val
    movl %eax, num
n115:
movl b14, %eax
cmp %eax, num
jge n114
    movl $-14, val
    movl %eax, num
n114:
movl b13, %eax
cmp %eax, num
jge n113
    movl $-13, val
    movl %eax, num
n113:
movl b12, %eax
cmp %eax, num
jge n112
    movl $-12, val
    movl %eax, num
n112:
movl b11, %eax
cmp %eax, num
jge n111
    movl $-11, val
    movl %eax, num
n111:
movl b10, %eax
cmp %eax, num
jge n110
    movl $-10, val
    movl %eax, num
n110:
movl b9, %eax
cmp %eax, num
jge n109
    movl $-9, val
    movl %eax, num
n109:
movl b8, %eax
cmp %eax, num
jge n108
    movl $-8, val
    movl %eax, num
n108:
movl b7, %eax
cmp %eax, num
jge n107
    movl $-7, val
    movl %eax, num
n107:
movl b6, %eax
cmp %eax, num
jge n106
    movl $-6, val
    movl %eax, num
n106:
movl b5, %eax
cmp %eax, num
jge n105
    movl $-5, val
    movl %eax, num
n105:
movl b4, %eax
cmp %eax, num
jge n104
    movl $-4, val
    movl %eax, num
n104:
movl b3, %eax
cmp %eax, num
jge n103
    movl $-3, val
    movl %eax, num
n103:
movl b2, %eax
cmp %eax, num
jge n102
    movl $-2, val
    movl %eax, num
n102:
movl b1, %eax
cmp %eax, num
jge n101
    movl $-1, val
    movl %eax, num
n101:
movl a0, %eax
cmp %eax, num
jge n0
    movl $0, val
    movl %eax, num
n0:
movl a1, %eax
cmp %eax, num
jge n1
    movl $1, val
    movl %eax, num
n1:
movl a2, %eax
cmp %eax, num
jge n2
    movl $2, val
    movl %eax, num
n2:
movl a3, %eax
cmp %eax, num
jge n3
    movl $3, val
    movl %eax, num
n3:
movl a4, %eax
cmp %eax, num
jge n4
    movl $4, val
    movl %eax, num
n4:
movl a5, %eax
cmp %eax, num
jge n5
    movl $5, val
    movl %eax, num
n5:
movl a6, %eax
cmp %eax, num
jge n6
    movl $6, val
    movl %eax, num
n6:
movl a7, %eax
cmp %eax, num
jge n7
    movl $7, val
    movl %eax, num
n7:
movl a8, %eax
cmp %eax, num
jge n8
    movl $8, val
    movl %eax, num
n8:
movl a9, %eax
cmp %eax, num
jge n9
    movl $9, val
    movl %eax, num
n9:
movl a10, %eax
cmp %eax, num
jge n10
    movl $10, val
    movl %eax, num
n10:
movl a11, %eax
cmp %eax, num
jge n11
    movl $11, val
    movl %eax, num
n11:
movl a12, %eax
cmp %eax, num
jge n12
    movl $12, val
    movl %eax, num
n12:
movl a13, %eax
cmp %eax, num
jge n13
    movl $13, val
    movl %eax, num
n13:
movl a14, %eax
cmp %eax, num
jge n14
    movl $14, val
    movl %eax, num
n14:
movl a15, %eax
cmp %eax, num
jge n15
    movl $15, val
    movl %eax, num
n15:
movl a16, %eax
cmp %eax, num
jge n16
    movl $16, val
    movl %eax, num
n16:
movl a17, %eax
cmp %eax, num
jge n17
    movl $17, val
    movl %eax, num
n17:
movl a18, %eax
cmp %eax, num
jge n18
    movl $18, val
    movl %eax, num
n18:
movl a19, %eax
cmp %eax, num
jge n19
    movl $19, val
    movl %eax, num
n19:
movl a20, %eax
cmp %eax, num
jge n20
    movl $20, val
    movl %eax, num
n20:
movl a21, %eax
cmp %eax, num
jge n21
    movl $21, val
    movl %eax, num
n21:
movl a22, %eax
cmp %eax, num
jge n22
    movl $22, val
    movl %eax, num
n22:
movl a23, %eax
cmp %eax, num
jge n23
    movl $23, val
    movl %eax, num
n23:
movl a24, %eax
cmp %eax, num
jge n24
    movl $24, val
    movl %eax, num
n24:
movl a25, %eax
cmp %eax, num
jge n25
    movl $25, val
    movl %eax, num
n25:
movl a26, %eax
cmp %eax, num
jge n26
    movl $26, val
    movl %eax, num
n26:
movl a27, %eax
cmp %eax, num
jge n27
    movl $27, val
    movl %eax, num
n27:
movl a28, %eax
cmp %eax, num
jge n28
    movl $28, val
    movl %eax, num
n28:
movl a29, %eax
cmp %eax, num
jge n29
    movl $29, val
    movl %eax, num
n29:
movl a30, %eax
cmp %eax, num
jge n30
    movl $30, val
    movl %eax, num
n30:
movl a31, %eax
cmp %eax, num
jge n31
    movl $31, val
    movl %eax, num
n31:
movl a32, %eax
cmp %eax, num
jge n32
    movl $32, val
    movl %eax, num
n32:
movl a33, %eax
cmp %eax, num
jge n33
    movl $33, val
    movl %eax, num
n33:
movl a34, %eax
cmp %eax, num
jge n34
    movl $34, val
    movl %eax, num
n34:
movl a35, %eax
cmp %eax, num
jge n35
    movl $35, val
    movl %eax, num
n35:
movl a36, %eax
cmp %eax, num
jge n36
    movl $36, val
    movl %eax, num
n36:
movl a37, %eax
cmp %eax, num
jge n37
    movl $37, val
    movl %eax, num
n37:
movl a38, %eax
cmp %eax, num
jge n38
    movl $38, val
    movl %eax, num
n38:
movl a39, %eax
cmp %eax, num
jge n39
    movl $39, val
    movl %eax, num
n39:
movl a40, %eax
cmp %eax, num
jge n40
    movl $40, val
    movl %eax, num
n40:
movl a41, %eax
cmp %eax, num
jge n41
    movl $41, val
    movl %eax, num
n41:
movl a42, %eax
cmp %eax, num
jge n42
    movl $42, val
    movl %eax, num
n42:
movl a43, %eax
cmp %eax, num
jge n43
    movl $43, val
    movl %eax, num
n43:
movl a44, %eax
cmp %eax, num
jge n44
    movl $44, val
    movl %eax, num
n44:
movl a45, %eax
cmp %eax, num
jge n45
    movl $45, val
    movl %eax, num
n45:
movl a46, %eax
cmp %eax, num
jge n46
    movl $46, val
    movl %eax, num
n46:
movl a47, %eax
cmp %eax, num
jge n47
    movl $47, val
    movl %eax, num
n47:
movl a48, %eax
cmp %eax, num
jge n48
    movl $48, val
    movl %eax, num
n48:
movl a49, %eax
cmp %eax, num
jge n49
    movl $49, val
    movl %eax, num
n49:
movl a50, %eax
cmp %eax, num
jge n50
    movl $50, val
    movl %eax, num
n50:
movl a51, %eax
cmp %eax, num
jge n51
    movl $51, val
    movl %eax, num
n51:
movl a52, %eax
cmp %eax, num
jge n52
    movl $52, val
    movl %eax, num
n52:
movl a53, %eax
cmp %eax, num
jge n53
    movl $53, val
    movl %eax, num
n53:
movl a54, %eax
cmp %eax, num
jge n54
    movl $54, val
    movl %eax, num
n54:
movl a55, %eax
cmp %eax, num
jge n55
    movl $55, val
    movl %eax, num
n55:
movl a56, %eax
cmp %eax, num
jge n56
    movl $56, val
    movl %eax, num
n56:
movl a57, %eax
cmp %eax, num
jge n57
    movl $57, val
    movl %eax, num
n57:
movl a58, %eax
cmp %eax, num
jge n58
    movl $58, val
    movl %eax, num
n58:
movl a59, %eax
cmp %eax, num
jge n59
    movl $59, val
    movl %eax, num
n59:
movl a60, %eax
cmp %eax, num
jge n60
    movl $60, val
    movl %eax, num
n60:
movl a61, %eax
cmp %eax, num
jge n61
    movl $61, val
    movl %eax, num
n61:
movl a62, %eax
cmp %eax, num
jge n62
    movl $62, val
    movl %eax, num
n62:
movl a63, %eax
cmp %eax, num
jge n63
    movl $63, val
    movl %eax, num
n63:
movl a64, %eax
cmp %eax, num
jge n64
    movl $64, val
    movl %eax, num
n64:
movl a65, %eax
cmp %eax, num
jge n65
    movl $65, val
    movl %eax, num
n65:
movl a66, %eax
cmp %eax, num
jge n66
    movl $66, val
    movl %eax, num
n66:
movl a67, %eax
cmp %eax, num
jge n67
    movl $67, val
    movl %eax, num
n67:
movl a68, %eax
cmp %eax, num
jge n68
    movl $68, val
    movl %eax, num
n68:
movl a69, %eax
cmp %eax, num
jge n69
    movl $69, val
    movl %eax, num
n69:
movl a70, %eax
cmp %eax, num
jge n70
    movl $70, val
    movl %eax, num
n70:
movl a71, %eax
cmp %eax, num
jge n71
    movl $71, val
    movl %eax, num
n71:
movl a72, %eax
cmp %eax, num
jge n72
    movl $72, val
    movl %eax, num
n72:
movl a73, %eax
cmp %eax, num
jge n73
    movl $73, val
    movl %eax, num
n73:
movl a74, %eax
cmp %eax, num
jge n74
    movl $74, val
    movl %eax, num
n74:
movl a75, %eax
cmp %eax, num
jge n75
    movl $75, val
    movl %eax, num
n75:
movl a76, %eax
cmp %eax, num
jge n76
    movl $76, val
    movl %eax, num
n76:
movl a77, %eax
cmp %eax, num
jge n77
    movl $77, val
    movl %eax, num
n77:
movl a78, %eax
cmp %eax, num
jge n78
    movl $78, val
    movl %eax, num
n78:
movl a79, %eax
cmp %eax, num
jge n79
    movl $79, val
    movl %eax, num
n79:
movl a80, %eax
cmp %eax, num
jge n80
    movl $80, val
    movl %eax, num
n80:
movl a81, %eax
cmp %eax, num
jge n81
    movl $81, val
    movl %eax, num
n81:
movl a82, %eax
cmp %eax, num
jge n82
    movl $82, val
    movl %eax, num
n82:
movl a83, %eax
cmp %eax, num
jge n83
    movl $83, val
    movl %eax, num
n83:
movl a84, %eax
cmp %eax, num
jge n84
    movl $84, val
    movl %eax, num
n84:
movl a85, %eax
cmp %eax, num
jge n85
    movl $85, val
    movl %eax, num
n85:
movl a86, %eax
cmp %eax, num
jge n86
    movl $86, val
    movl %eax, num
n86:
movl a87, %eax
cmp %eax, num
jge n87
    movl $87, val
    movl %eax, num
n87:
movl a88, %eax
cmp %eax, num
jge n88
    movl $88, val
    movl %eax, num
n88:
movl a89, %eax
cmp %eax, num
jge n89
    movl $89, val
    movl %eax, num
n89:
movl a90, %eax
cmp %eax, num
jge n90
    movl $90, val
    movl %eax, num
n90:
movl a91, %eax
cmp %eax, num
jge n91
    movl $91, val
    movl %eax, num
n91:
movl a92, %eax
cmp %eax, num
jge n92
    movl $92, val
    movl %eax, num
n92:
movl a93, %eax
cmp %eax, num
jge n93
    movl $93, val
    movl %eax, num
n93:
movl a94, %eax
cmp %eax, num
jge n94
    movl $94, val
    movl %eax, num
n94:
movl a95, %eax
cmp %eax, num
jge n95
    movl $95, val
    movl %eax, num
n95:
movl a96, %eax
cmp %eax, num
jge n96
    movl $96, val
    movl %eax, num
n96:
movl a97, %eax
cmp %eax, num
jge n97
    movl $97, val
    movl %eax, num
n97:
movl a98, %eax
cmp %eax, num
jge n98
    movl $98, val
    movl %eax, num
n98:
movl a99, %eax
cmp %eax, num
jge n99
    movl $99, val
    movl %eax, num
n99:
movl a100, %eax
cmp %eax, num
jge n100
    movl $100, val
    movl %eax, num
n100:

    cmp $0, val
    jge skip4
        movl $45, a
        movl $4, %eax
        movl $1, %ebx
        movl $a, %ecx
        movl $1, %edx
        int $0x80  
        movl val, %eax
        movl $-1, %esi
        imull %esi
        movl %eax, val      
    skip4:

    movl val, %edi
    cmp $100, %edi
    jl nt1
        movl %edi, %eax
        xor %edx, %edx
        movl $100, %ecx
        divl %ecx
        movl %eax, a
        add $48, a
        movl $100, %esi
        mull %esi
        sub %eax, %edi
        movl $4, %eax
        movl $1, %ebx
        movl $a, %ecx
        movl $1, %edx
        int $0x80
        cmp $10, %edi
        jge nt1
            movl $48, a
            movl $4, %eax
            movl $1, %ebx
            movl $a, %ecx
            movl $1, %edx
            int $0x80
        jmp nt2
    nt1:
    cmp $10, %edi
    jl nt2
        movl %edi, %eax
        xor %edx, %edx
        movl $10, %ecx
        divl %ecx
        movl %eax, a
        add $48, a
        movl $10, %esi
        mull %esi
        sub %eax, %edi
        movl $4, %eax
        movl $1, %ebx
        movl $a, %ecx
        movl $1, %edx
        int $0x80
    nt2:
        movl %edi, %eax
        movl %eax, a
        add $48, a
        movl $4, %eax
        movl $1, %ebx
        movl $a, %ecx
        movl $1, %edx
        int $0x80
        cmp $0, %edi
    nt3:

jmp end
func1:
cmp $-100, d
jne next200
    movl b100, %eax
    inc %eax
    movl %eax, b100
    jmp cont
next200:
cmp $-99, d
jne next199
    movl b99, %eax
    inc %eax
    movl %eax, b99
    jmp cont
next199:
cmp $-98, d
jne next198
    movl b98, %eax
    inc %eax
    movl %eax, b98
    jmp cont
next198:
cmp $-97, d
jne next197
    movl b97, %eax
    inc %eax
    movl %eax, b97
    jmp cont
next197:
cmp $-96, d
jne next196
    movl b96, %eax
    inc %eax
    movl %eax, b96
    jmp cont
next196:
cmp $-95, d
jne next195
    movl b95, %eax
    inc %eax
    movl %eax, b95
    jmp cont
next195:
cmp $-94, d
jne next194
    movl b94, %eax
    inc %eax
    movl %eax, b94
    jmp cont
next194:
cmp $-93, d
jne next193
    movl b93, %eax
    inc %eax
    movl %eax, b93
    jmp cont
next193:
cmp $-92, d
jne next192
    movl b92, %eax
    inc %eax
    movl %eax, b92
    jmp cont
next192:
cmp $-91, d
jne next191
    movl b91, %eax
    inc %eax
    movl %eax, b91
    jmp cont
next191:
cmp $-90, d
jne next190
    movl b90, %eax
    inc %eax
    movl %eax, b90
    jmp cont
next190:
cmp $-89, d
jne next189
    movl b89, %eax
    inc %eax
    movl %eax, b89
    jmp cont
next189:
cmp $-88, d
jne next188
    movl b88, %eax
    inc %eax
    movl %eax, b88
    jmp cont
next188:
cmp $-87, d
jne next187
    movl b87, %eax
    inc %eax
    movl %eax, b87
    jmp cont
next187:
cmp $-86, d
jne next186
    movl b86, %eax
    inc %eax
    movl %eax, b86
    jmp cont
next186:
cmp $-85, d
jne next185
    movl b85, %eax
    inc %eax
    movl %eax, b85
    jmp cont
next185:
cmp $-84, d
jne next184
    movl b84, %eax
    inc %eax
    movl %eax, b84
    jmp cont
next184:
cmp $-83, d
jne next183
    movl b83, %eax
    inc %eax
    movl %eax, b83
    jmp cont
next183:
cmp $-82, d
jne next182
    movl b82, %eax
    inc %eax
    movl %eax, b82
    jmp cont
next182:
cmp $-81, d
jne next181
    movl b81, %eax
    inc %eax
    movl %eax, b81
    jmp cont
next181:
cmp $-80, d
jne next180
    movl b80, %eax
    inc %eax
    movl %eax, b80
    jmp cont
next180:
cmp $-79, d
jne next179
    movl b79, %eax
    inc %eax
    movl %eax, b79
    jmp cont
next179:
cmp $-78, d
jne next178
    movl b78, %eax
    inc %eax
    movl %eax, b78
    jmp cont
next178:
cmp $-77, d
jne next177
    movl b77, %eax
    inc %eax
    movl %eax, b77
    jmp cont
next177:
cmp $-76, d
jne next176
    movl b76, %eax
    inc %eax
    movl %eax, b76
    jmp cont
next176:
cmp $-75, d
jne next175
    movl b75, %eax
    inc %eax
    movl %eax, b75
    jmp cont
next175:
cmp $-74, d
jne next174
    movl b74, %eax
    inc %eax
    movl %eax, b74
    jmp cont
next174:
cmp $-73, d
jne next173
    movl b73, %eax
    inc %eax
    movl %eax, b73
    jmp cont
next173:
cmp $-72, d
jne next172
    movl b72, %eax
    inc %eax
    movl %eax, b72
    jmp cont
next172:
cmp $-71, d
jne next171
    movl b71, %eax
    inc %eax
    movl %eax, b71
    jmp cont
next171:
cmp $-70, d
jne next170
    movl b70, %eax
    inc %eax
    movl %eax, b70
    jmp cont
next170:
cmp $-69, d
jne next169
    movl b69, %eax
    inc %eax
    movl %eax, b69
    jmp cont
next169:
cmp $-68, d
jne next168
    movl b68, %eax
    inc %eax
    movl %eax, b68
    jmp cont
next168:
cmp $-67, d
jne next167
    movl b67, %eax
    inc %eax
    movl %eax, b67
    jmp cont
next167:
cmp $-66, d
jne next166
    movl b66, %eax
    inc %eax
    movl %eax, b66
    jmp cont
next166:
cmp $-65, d
jne next165
    movl b65, %eax
    inc %eax
    movl %eax, b65
    jmp cont
next165:
cmp $-64, d
jne next164
    movl b64, %eax
    inc %eax
    movl %eax, b64
    jmp cont
next164:
cmp $-63, d
jne next163
    movl b63, %eax
    inc %eax
    movl %eax, b63
    jmp cont
next163:
cmp $-62, d
jne next162
    movl b62, %eax
    inc %eax
    movl %eax, b62
    jmp cont
next162:
cmp $-61, d
jne next161
    movl b61, %eax
    inc %eax
    movl %eax, b61
    jmp cont
next161:
cmp $-60, d
jne next160
    movl b60, %eax
    inc %eax
    movl %eax, b60
    jmp cont
next160:
cmp $-59, d
jne next159
    movl b59, %eax
    inc %eax
    movl %eax, b59
    jmp cont
next159:
cmp $-58, d
jne next158
    movl b58, %eax
    inc %eax
    movl %eax, b58
    jmp cont
next158:
cmp $-57, d
jne next157
    movl b57, %eax
    inc %eax
    movl %eax, b57
    jmp cont
next157:
cmp $-56, d
jne next156
    movl b56, %eax
    inc %eax
    movl %eax, b56
    jmp cont
next156:
cmp $-55, d
jne next155
    movl b55, %eax
    inc %eax
    movl %eax, b55
    jmp cont
next155:
cmp $-54, d
jne next154
    movl b54, %eax
    inc %eax
    movl %eax, b54
    jmp cont
next154:
cmp $-53, d
jne next153
    movl b53, %eax
    inc %eax
    movl %eax, b53
    jmp cont
next153:
cmp $-52, d
jne next152
    movl b52, %eax
    inc %eax
    movl %eax, b52
    jmp cont
next152:
cmp $-51, d
jne next151
    movl b51, %eax
    inc %eax
    movl %eax, b51
    jmp cont
next151:
cmp $-50, d
jne next150
    movl b50, %eax
    inc %eax
    movl %eax, b50
    jmp cont
next150:
cmp $-49, d
jne next149
    movl b49, %eax
    inc %eax
    movl %eax, b49
    jmp cont
next149:
cmp $-48, d
jne next148
    movl b48, %eax
    inc %eax
    movl %eax, b48
    jmp cont
next148:
cmp $-47, d
jne next147
    movl b47, %eax
    inc %eax
    movl %eax, b47
    jmp cont
next147:
cmp $-46, d
jne next146
    movl b46, %eax
    inc %eax
    movl %eax, b46
    jmp cont
next146:
cmp $-45, d
jne next145
    movl b45, %eax
    inc %eax
    movl %eax, b45
    jmp cont
next145:
cmp $-44, d
jne next144
    movl b44, %eax
    inc %eax
    movl %eax, b44
    jmp cont
next144:
cmp $-43, d
jne next143
    movl b43, %eax
    inc %eax
    movl %eax, b43
    jmp cont
next143:
cmp $-42, d
jne next142
    movl b42, %eax
    inc %eax
    movl %eax, b42
    jmp cont
next142:
cmp $-41, d
jne next141
    movl b41, %eax
    inc %eax
    movl %eax, b41
    jmp cont
next141:
cmp $-40, d
jne next140
    movl b40, %eax
    inc %eax
    movl %eax, b40
    jmp cont
next140:
cmp $-39, d
jne next139
    movl b39, %eax
    inc %eax
    movl %eax, b39
    jmp cont
next139:
cmp $-38, d
jne next138
    movl b38, %eax
    inc %eax
    movl %eax, b38
    jmp cont
next138:
cmp $-37, d
jne next137
    movl b37, %eax
    inc %eax
    movl %eax, b37
    jmp cont
next137:
cmp $-36, d
jne next136
    movl b36, %eax
    inc %eax
    movl %eax, b36
    jmp cont
next136:
cmp $-35, d
jne next135
    movl b35, %eax
    inc %eax
    movl %eax, b35
    jmp cont
next135:
cmp $-34, d
jne next134
    movl b34, %eax
    inc %eax
    movl %eax, b34
    jmp cont
next134:
cmp $-33, d
jne next133
    movl b33, %eax
    inc %eax
    movl %eax, b33
    jmp cont
next133:
cmp $-32, d
jne next132
    movl b32, %eax
    inc %eax
    movl %eax, b32
    jmp cont
next132:
cmp $-31, d
jne next131
    movl b31, %eax
    inc %eax
    movl %eax, b31
    jmp cont
next131:
cmp $-30, d
jne next130
    movl b30, %eax
    inc %eax
    movl %eax, b30
    jmp cont
next130:
cmp $-29, d
jne next129
    movl b29, %eax
    inc %eax
    movl %eax, b29
    jmp cont
next129:
cmp $-28, d
jne next128
    movl b28, %eax
    inc %eax
    movl %eax, b28
    jmp cont
next128:
cmp $-27, d
jne next127
    movl b27, %eax
    inc %eax
    movl %eax, b27
    jmp cont
next127:
cmp $-26, d
jne next126
    movl b26, %eax
    inc %eax
    movl %eax, b26
    jmp cont
next126:
cmp $-25, d
jne next125
    movl b25, %eax
    inc %eax
    movl %eax, b25
    jmp cont
next125:
cmp $-24, d
jne next124
    movl b24, %eax
    inc %eax
    movl %eax, b24
    jmp cont
next124:
cmp $-23, d
jne next123
    movl b23, %eax
    inc %eax
    movl %eax, b23
    jmp cont
next123:
cmp $-22, d
jne next122
    movl b22, %eax
    inc %eax
    movl %eax, b22
    jmp cont
next122:
cmp $-21, d
jne next121
    movl b21, %eax
    inc %eax
    movl %eax, b21
    jmp cont
next121:
cmp $-20, d
jne next120
    movl b20, %eax
    inc %eax
    movl %eax, b20
    jmp cont
next120:
cmp $-19, d
jne next119
    movl b19, %eax
    inc %eax
    movl %eax, b19
    jmp cont
next119:
cmp $-18, d
jne next118
    movl b18, %eax
    inc %eax
    movl %eax, b18
    jmp cont
next118:
cmp $-17, d
jne next117
    movl b17, %eax
    inc %eax
    movl %eax, b17
    jmp cont
next117:
cmp $-16, d
jne next116
    movl b16, %eax
    inc %eax
    movl %eax, b16
    jmp cont
next116:
cmp $-15, d
jne next115
    movl b15, %eax
    inc %eax
    movl %eax, b15
    jmp cont
next115:
cmp $-14, d
jne next114
    movl b14, %eax
    inc %eax
    movl %eax, b14
    jmp cont
next114:
cmp $-13, d
jne next113
    movl b13, %eax
    inc %eax
    movl %eax, b13
    jmp cont
next113:
cmp $-12, d
jne next112
    movl b12, %eax
    inc %eax
    movl %eax, b12
    jmp cont
next112:
cmp $-11, d
jne next111
    movl b11, %eax
    inc %eax
    movl %eax, b11
    jmp cont
next111:
cmp $-10, d
jne next110
    movl b10, %eax
    inc %eax
    movl %eax, b10
    jmp cont
next110:
cmp $-9, d
jne next109
    movl b9, %eax
    inc %eax
    movl %eax, b9
    jmp cont
next109:
cmp $-8, d
jne next108
    movl b8, %eax
    inc %eax
    movl %eax, b8
    jmp cont
next108:
cmp $-7, d
jne next107
    movl b7, %eax
    inc %eax
    movl %eax, b7
    jmp cont
next107:
cmp $-6, d
jne next106
    movl b6, %eax
    inc %eax
    movl %eax, b6
    jmp cont
next106:
cmp $-5, d
jne next105
    movl b5, %eax
    inc %eax
    movl %eax, b5
    jmp cont
next105:
cmp $-4, d
jne next104
    movl b4, %eax
    inc %eax
    movl %eax, b4
    jmp cont
next104:
cmp $-3, d
jne next103
    movl b3, %eax
    inc %eax
    movl %eax, b3
    jmp cont
next103:
cmp $-2, d
jne next102
    movl b2, %eax
    inc %eax
    movl %eax, b2
    jmp cont
next102:
cmp $-1, d
jne next101
    movl b1, %eax
    inc %eax
    movl %eax, b1
    jmp cont
next101:
cmp $0, d
jne next0
    movl a0, %eax
    inc %eax
    movl %eax, a0
    jmp cont
next0:
cmp $1, d
jne next1
    movl a1, %eax
    inc %eax
    movl %eax, a1
    jmp cont
next1:
cmp $2, d
jne next2
    movl a2, %eax
    inc %eax
    movl %eax, a2
    jmp cont
next2:
cmp $3, d
jne next3
    movl a3, %eax
    inc %eax
    movl %eax, a3
    jmp cont
next3:
cmp $4, d
jne next4
    movl a4, %eax
    inc %eax
    movl %eax, a4
    jmp cont
next4:
cmp $5, d
jne next5
    movl a5, %eax
    inc %eax
    movl %eax, a5
    jmp cont
next5:
cmp $6, d
jne next6
    movl a6, %eax
    inc %eax
    movl %eax, a6
    jmp cont
next6:
cmp $7, d
jne next7
    movl a7, %eax
    inc %eax
    movl %eax, a7
    jmp cont
next7:
cmp $8, d
jne next8
    movl a8, %eax
    inc %eax
    movl %eax, a8
    jmp cont
next8:
cmp $9, d
jne next9
    movl a9, %eax
    inc %eax
    movl %eax, a9
    jmp cont
next9:
cmp $10, d
jne next10
    movl a10, %eax
    inc %eax
    movl %eax, a10
    jmp cont
next10:
cmp $11, d
jne next11
    movl a11, %eax
    inc %eax
    movl %eax, a11
    jmp cont
next11:
cmp $12, d
jne next12
    movl a12, %eax
    inc %eax
    movl %eax, a12
    jmp cont
next12:
cmp $13, d
jne next13
    movl a13, %eax
    inc %eax
    movl %eax, a13
    jmp cont
next13:
cmp $14, d
jne next14
    movl a14, %eax
    inc %eax
    movl %eax, a14
    jmp cont
next14:
cmp $15, d
jne next15
    movl a15, %eax
    inc %eax
    movl %eax, a15
    jmp cont
next15:
cmp $16, d
jne next16
    movl a16, %eax
    inc %eax
    movl %eax, a16
    jmp cont
next16:
cmp $17, d
jne next17
    movl a17, %eax
    inc %eax
    movl %eax, a17
    jmp cont
next17:
cmp $18, d
jne next18
    movl a18, %eax
    inc %eax
    movl %eax, a18
    jmp cont
next18:
cmp $19, d
jne next19
    movl a19, %eax
    inc %eax
    movl %eax, a19
    jmp cont
next19:
cmp $20, d
jne next20
    movl a20, %eax
    inc %eax
    movl %eax, a20
    jmp cont
next20:
cmp $21, d
jne next21
    movl a21, %eax
    inc %eax
    movl %eax, a21
    jmp cont
next21:
cmp $22, d
jne next22
    movl a22, %eax
    inc %eax
    movl %eax, a22
    jmp cont
next22:
cmp $23, d
jne next23
    movl a23, %eax
    inc %eax
    movl %eax, a23
    jmp cont
next23:
cmp $24, d
jne next24
    movl a24, %eax
    inc %eax
    movl %eax, a24
    jmp cont
next24:
cmp $25, d
jne next25
    movl a25, %eax
    inc %eax
    movl %eax, a25
    jmp cont
next25:
cmp $26, d
jne next26
    movl a26, %eax
    inc %eax
    movl %eax, a26
    jmp cont
next26:
cmp $27, d
jne next27
    movl a27, %eax
    inc %eax
    movl %eax, a27
    jmp cont
next27:
cmp $28, d
jne next28
    movl a28, %eax
    inc %eax
    movl %eax, a28
    jmp cont
next28:
cmp $29, d
jne next29
    movl a29, %eax
    inc %eax
    movl %eax, a29
    jmp cont
next29:
cmp $30, d
jne next30
    movl a30, %eax
    inc %eax
    movl %eax, a30
    jmp cont
next30:
cmp $31, d
jne next31
    movl a31, %eax
    inc %eax
    movl %eax, a31
    jmp cont
next31:
cmp $32, d
jne next32
    movl a32, %eax
    inc %eax
    movl %eax, a32
    jmp cont
next32:
cmp $33, d
jne next33
    movl a33, %eax
    inc %eax
    movl %eax, a33
    jmp cont
next33:
cmp $34, d
jne next34
    movl a34, %eax
    inc %eax
    movl %eax, a34
    jmp cont
next34:
cmp $35, d
jne next35
    movl a35, %eax
    inc %eax
    movl %eax, a35
    jmp cont
next35:
cmp $36, d
jne next36
    movl a36, %eax
    inc %eax
    movl %eax, a36
    jmp cont
next36:
cmp $37, d
jne next37
    movl a37, %eax
    inc %eax
    movl %eax, a37
    jmp cont
next37:
cmp $38, d
jne next38
    movl a38, %eax
    inc %eax
    movl %eax, a38
    jmp cont
next38:
cmp $39, d
jne next39
    movl a39, %eax
    inc %eax
    movl %eax, a39
    jmp cont
next39:
cmp $40, d
jne next40
    movl a40, %eax
    inc %eax
    movl %eax, a40
    jmp cont
next40:
cmp $41, d
jne next41
    movl a41, %eax
    inc %eax
    movl %eax, a41
    jmp cont
next41:
cmp $42, d
jne next42
    movl a42, %eax
    inc %eax
    movl %eax, a42
    jmp cont
next42:
cmp $43, d
jne next43
    movl a43, %eax
    inc %eax
    movl %eax, a43
    jmp cont
next43:
cmp $44, d
jne next44
    movl a44, %eax
    inc %eax
    movl %eax, a44
    jmp cont
next44:
cmp $45, d
jne next45
    movl a45, %eax
    inc %eax
    movl %eax, a45
    jmp cont
next45:
cmp $46, d
jne next46
    movl a46, %eax
    inc %eax
    movl %eax, a46
    jmp cont
next46:
cmp $47, d
jne next47
    movl a47, %eax
    inc %eax
    movl %eax, a47
    jmp cont
next47:
cmp $48, d
jne next48
    movl a48, %eax
    inc %eax
    movl %eax, a48
    jmp cont
next48:
cmp $49, d
jne next49
    movl a49, %eax
    inc %eax
    movl %eax, a49
    jmp cont
next49:
cmp $50, d
jne next50
    movl a50, %eax
    inc %eax
    movl %eax, a50
    jmp cont
next50:
cmp $51, d
jne next51
    movl a51, %eax
    inc %eax
    movl %eax, a51
    jmp cont
next51:
cmp $52, d
jne next52
    movl a52, %eax
    inc %eax
    movl %eax, a52
    jmp cont
next52:
cmp $53, d
jne next53
    movl a53, %eax
    inc %eax
    movl %eax, a53
    jmp cont
next53:
cmp $54, d
jne next54
    movl a54, %eax
    inc %eax
    movl %eax, a54
    jmp cont
next54:
cmp $55, d
jne next55
    movl a55, %eax
    inc %eax
    movl %eax, a55
    jmp cont
next55:
cmp $56, d
jne next56
    movl a56, %eax
    inc %eax
    movl %eax, a56
    jmp cont
next56:
cmp $57, d
jne next57
    movl a57, %eax
    inc %eax
    movl %eax, a57
    jmp cont
next57:
cmp $58, d
jne next58
    movl a58, %eax
    inc %eax
    movl %eax, a58
    jmp cont
next58:
cmp $59, d
jne next59
    movl a59, %eax
    inc %eax
    movl %eax, a59
    jmp cont
next59:
cmp $60, d
jne next60
    movl a60, %eax
    inc %eax
    movl %eax, a60
    jmp cont
next60:
cmp $61, d
jne next61
    movl a61, %eax
    inc %eax
    movl %eax, a61
    jmp cont
next61:
cmp $62, d
jne next62
    movl a62, %eax
    inc %eax
    movl %eax, a62
    jmp cont
next62:
cmp $63, d
jne next63
    movl a63, %eax
    inc %eax
    movl %eax, a63
    jmp cont
next63:
cmp $64, d
jne next64
    movl a64, %eax
    inc %eax
    movl %eax, a64
    jmp cont
next64:
cmp $65, d
jne next65
    movl a65, %eax
    inc %eax
    movl %eax, a65
    jmp cont
next65:
cmp $66, d
jne next66
    movl a66, %eax
    inc %eax
    movl %eax, a66
    jmp cont
next66:
cmp $67, d
jne next67
    movl a67, %eax
    inc %eax
    movl %eax, a67
    jmp cont
next67:
cmp $68, d
jne next68
    movl a68, %eax
    inc %eax
    movl %eax, a68
    jmp cont
next68:
cmp $69, d
jne next69
    movl a69, %eax
    inc %eax
    movl %eax, a69
    jmp cont
next69:
cmp $70, d
jne next70
    movl a70, %eax
    inc %eax
    movl %eax, a70
    jmp cont
next70:
cmp $71, d
jne next71
    movl a71, %eax
    inc %eax
    movl %eax, a71
    jmp cont
next71:
cmp $72, d
jne next72
    movl a72, %eax
    inc %eax
    movl %eax, a72
    jmp cont
next72:
cmp $73, d
jne next73
    movl a73, %eax
    inc %eax
    movl %eax, a73
    jmp cont
next73:
cmp $74, d
jne next74
    movl a74, %eax
    inc %eax
    movl %eax, a74
    jmp cont
next74:
cmp $75, d
jne next75
    movl a75, %eax
    inc %eax
    movl %eax, a75
    jmp cont
next75:
cmp $76, d
jne next76
    movl a76, %eax
    inc %eax
    movl %eax, a76
    jmp cont
next76:
cmp $77, d
jne next77
    movl a77, %eax
    inc %eax
    movl %eax, a77
    jmp cont
next77:
cmp $78, d
jne next78
    movl a78, %eax
    inc %eax
    movl %eax, a78
    jmp cont
next78:
cmp $79, d
jne next79
    movl a79, %eax
    inc %eax
    movl %eax, a79
    jmp cont
next79:
cmp $80, d
jne next80
    movl a80, %eax
    inc %eax
    movl %eax, a80
    jmp cont
next80:
cmp $81, d
jne next81
    movl a81, %eax
    inc %eax
    movl %eax, a81
    jmp cont
next81:
cmp $82, d
jne next82
    movl a82, %eax
    inc %eax
    movl %eax, a82
    jmp cont
next82:
cmp $83, d
jne next83
    movl a83, %eax
    inc %eax
    movl %eax, a83
    jmp cont
next83:
cmp $84, d
jne next84
    movl a84, %eax
    inc %eax
    movl %eax, a84
    jmp cont
next84:
cmp $85, d
jne next85
    movl a85, %eax
    inc %eax
    movl %eax, a85
    jmp cont
next85:
cmp $86, d
jne next86
    movl a86, %eax
    inc %eax
    movl %eax, a86
    jmp cont
next86:
cmp $87, d
jne next87
    movl a87, %eax
    inc %eax
    movl %eax, a87
    jmp cont
next87:
cmp $88, d
jne next88
    movl a88, %eax
    inc %eax
    movl %eax, a88
    jmp cont
next88:
cmp $89, d
jne next89
    movl a89, %eax
    inc %eax
    movl %eax, a89
    jmp cont
next89:
cmp $90, d
jne next90
    movl a90, %eax
    inc %eax
    movl %eax, a90
    jmp cont
next90:
cmp $91, d
jne next91
    movl a91, %eax
    inc %eax
    movl %eax, a91
    jmp cont
next91:
cmp $92, d
jne next92
    movl a92, %eax
    inc %eax
    movl %eax, a92
    jmp cont
next92:
cmp $93, d
jne next93
    movl a93, %eax
    inc %eax
    movl %eax, a93
    jmp cont
next93:
cmp $94, d
jne next94
    movl a94, %eax
    inc %eax
    movl %eax, a94
    jmp cont
next94:
cmp $95, d
jne next95
    movl a95, %eax
    inc %eax
    movl %eax, a95
    jmp cont
next95:
cmp $96, d
jne next96
    movl a96, %eax
    inc %eax
    movl %eax, a96
    jmp cont
next96:
cmp $97, d
jne next97
    movl a97, %eax
    inc %eax
    movl %eax, a97
    jmp cont
next97:
cmp $98, d
jne next98
    movl a98, %eax
    inc %eax
    movl %eax, a98
    jmp cont
next98:
cmp $99, d
jne next99
    movl a99, %eax
    inc %eax
    movl %eax, a99
    jmp cont
next99:
cmp $100, d
jne next100
    movl a100, %eax
    inc %eax
    movl %eax, a100
    jmp cont
next100:
cont:
jmp return1
end:
_exit:
mov $1, %eax
xor %ebx, %ebx
int $0x80
