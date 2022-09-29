import java.util.Stack;

public class Palindrome {

    public static void palindrome(String str) {             //투포인터 방식
        int left = 0;                                       //left는 제일 첫번째 원소
        int right = str.length() - 1;                       //right는 제일 마지막 원소

        while(true) {
            if(str.charAt(left) != str.charAt(right)) {     //String의 첫번째 원소와 마지막원소가 같지않으면
                System.out.println("not palindrome");       //같지않음 출력
                break;                                      //탈출
            }

            left += 1;                                      //첫번재원소와 마지막원소가 같으면 left는 한칸 뒤로
            right -= 1;                                     //첫번째원소와 마지막원소가 같으면 right는 한칸 앞으로

            if (left >= right) {                            //만약 left와 right가 만나게된다면(커진다면)
                System.out.println("palindrome");           //출력
                break;                                      //탈출
            }
        }
    }

    public static void main(String[] args) {                //테스트코드
        String str = "aaabbaaa";
        Stack<Integer> stack = new Stack<>();

        palindrome(str);
    }
}