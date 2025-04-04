N, Q = map(int, input().split())
box_to_label = list(range(N))
label_to_box = list(range(N))
pigeon_to_box = list(range(N))

output = []
for _ in range(Q):
    op = input().split()
    t = int(op[0])
    if t == 1:
        pigeon = int(op[1])
        to = int(op[2])
        pigeon_to_box[pigeon - 1] = label_to_box[to - 1]
    elif t == 2:
        label0 = int(op[1])
        label1 = int(op[2])
        label_to_box[label0 - 1], label_to_box[label1 - 1] = label_to_box[label1 - 1], label_to_box[label0 - 1]
        a = label_to_box[label0 - 1]
        b = label_to_box[label1 - 1]
        box_to_label[a], box_to_label[b] = box_to_label[b], box_to_label[a]
    else:
        pigeon = int(op[1])
        result = box_to_label[pigeon_to_box[pigeon - 1]] + 1
        output.append(str(result))

print("\n".join(output))
