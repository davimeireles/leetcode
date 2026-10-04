import java.util.Arrays;

public class IsPalindrome {
    public boolean isPalindrome(int x) {
        String number = Integer.toString(x);
        int size = number.length();

        for (int i = 0; i < size; i++) {
            if (number.charAt(i) == number.charAt(size - 1))
                size--;
            else
                return false;
        }
        return true;
    }

    public static void main(String[] args) {
        TwoSum twoSum = new TwoSum();
        IsPalindrome palindrome = new IsPalindrome();

        if (palindrome.isPalindrome(121))
            System.out.println("True");
        else
            System.out.println("False");

        if (palindrome.isPalindrome(-121))
            System.out.println("True");
        else
            System.out.println("False");

        if (palindrome.isPalindrome(10))
            System.out.println("True");
        else
            System.out.println("False");
    }
}