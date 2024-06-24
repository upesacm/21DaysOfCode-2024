#Day3-Question1-
def is_complete(sentence):
    alphabet = set('abcdefghijklmnopqrstuvwxyz')

    sentence_set = set(sentence.lower())
    
    if alphabet.issubset(sentence_set):
        return "complete"
    else:
        return "incomplete"

sentence = input("Enter the sentence : ")
print(is_complete(sentence)) 
