
/**
 * P1662
 */
public class P1662 {

    public boolean arrayStringsAreEqual(String[] word1, String[] word2) {
        String str1 = "";
        String str2 = "";
        for (String string : word1) {
            str1 += string;
        }
        for (String string : word2) {
            str2 += string;
        }

        if(str1.equals(str2))
            return true;
        return false;
    }
}