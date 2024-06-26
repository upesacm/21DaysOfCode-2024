def is_pangram(sentence):
    alphabet = set("abcdefghijklmnopqrstuvwxyz")
    sentence_set = set(sentence.lower())
    if alphabet <= sentence_set:
        return "complete"
    else:
        return "incomplete"
sentence = input("Enter a sentence: ")
print(is_pangram(sentence))
