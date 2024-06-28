sentence = "The quick brown fox jumps over the lazy dog"
sentence_lower = sentence.lower()
letters = set()

for char in sentence_lower:
    if 'a' <= char <= 'z':
        letters.add(char)
    if len(letters) == 26:
        break

if len(letters) == 26:
    print("complete")
else:
    print("incomplete")
