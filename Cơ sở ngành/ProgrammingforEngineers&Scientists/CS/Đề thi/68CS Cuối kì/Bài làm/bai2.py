# Câu 2: Mã hóa Pig Latin

def pig_latin_word(word):
    vowels = 'aeiouAEIOU'
    if word[0] in vowels:
        return word + "way"
    else:
        return word[1:] + word[0] + "ay"

file_path = 'input.txt'

with open(file_path, 'r', encoding='utf-8') as f:
    text = f.read()

# Tách từ, mã hóa, rồi ghép lại
words = text.split()
encoded_words = [pig_latin_word(w) for w in words]

encoded_text = ' '.join(encoded_words)
print("Nội dung sau khi mã hóa Pig Latin:")
print(encoded_text)
