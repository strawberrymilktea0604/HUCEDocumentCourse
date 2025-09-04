package bai4;

public class bai4 {
    private String string;

    int vowels = 0;
    int con = 0;
    public bai4 (String str) {
        this.string = str;
        this.parsse();
    }

    private void parsse() {

        int a = string.length();
        for (int i = 0; i < a; i++) {
            if (this.isVowel(string.charAt(i))) {
                vowels++;
            }else{
                if (this.isConsonant(string.charAt(i))) {
                    con++;
                }
            }
        }
    }
    public int getVowels() {
        return vowels;
    }

    private boolean isVowel(char c) {
        return (c == 'a' || c == 'e'
                || c == 'i' || c == 'o'
                || c == 'u');
    }

    private boolean isConsonant(char c) {
        return (((c >= 'a' && c <= 'z') || (c >= 'A' && c >= 'Z')) && !isVowel(c));
    }
    public int getConsonants() {
        return con;
    }
}
