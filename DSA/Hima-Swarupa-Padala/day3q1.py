def is_pangram(sentence):
    alphabet = "abcdefghijklmnopqrstuvwxyz"
    sentence = sentence.lower()
    for letter in alphabet:
        if letter not in sentence:
            return "incomplete"
    return "complete"
sentence = "The quick brown fox jumps over the lazy dog"
print(is_pangram(sentence))  