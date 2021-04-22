
public class P344 {
    public void reverseString(char[] s) {
        char[] s2 = new char[s.length];
        for (int i = s.length; i > 0; i--) {
            s2[s.length-i] = s[i-1];
        }
        for (int i = 0; i < s2.length; i++) {
            s[i] = s2[i];
        }
    }

    public static void main(String[] args) {
        P344 app = new P344();
        char[] s = {'h','e','l','l','o'};
        app.reverseString(s);
        
    }
}
