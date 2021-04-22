/**
 * https://leetcode.com/problems/monotone-increasing-digits/
 */

public class P738 {

    public int monotoneIncreasingDigits(int N) {
        
        char[] ch = String.valueOf(N).toCharArray();

        int l = ch.length;

        for(int i=l-1; i>0; i--){
            if(ch[i] < ch[i-1]){
                l = i-1;
                ch[i-1]--;
            }
        }
        for(int i=l+1; i<ch.length; i++){
            ch[i] = '9';
        }
        return Integer.parseInt(new String(ch));
    }

    public static void main(String[] args) {        
        P738 app = new P738();
        int result = app.monotoneIncreasingDigits(332);
        System.out.println(result);
    }
}
