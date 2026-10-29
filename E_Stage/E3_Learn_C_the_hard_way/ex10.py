
import sys

# 获取命令行参数
argv = sys.argv
argc = len(argv)

# 遍历并打印命令行参数
for i in range(1, argc):
    print(f"arg {i}: {argv[i]}")

# 创建字符串数组
states = [
    "California", "Oregon",
    "Washington", "Texas"
]

num_states = 4

# 遍历并打印数组
for i in range(num_states):
    print(f"state {i}: {states[i]}")
