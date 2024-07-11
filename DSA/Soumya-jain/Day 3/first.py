def is_pangram(sentence):
    alphabet = set("abcdefghijklmnopqrstuvwxyz")
    sentence_letters = set(sentence.lower())

    if alphabet.issubset(sentence_letters):
        return "complete"
    else:
        return "incomplete"
    
    
sentence = input("Enter the sentence : ")
print(is_pangram(sentence))