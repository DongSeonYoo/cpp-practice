package Algorithm;

public class BinarySearch {
        public static int solution(int[] array, int target) {
            int left = 0;                           //배열의 처음 인덱스를 가리킴
            int right = array.length - 1;           //배열의 마지막 인덱스를 가리킴

            while(left <= right) {                  //left가 right를 역전할때까지

                int pivot = (left + right) / 2;     //피봇은 배열의 중간인덱스를 가르킴 left, right가 바뀔때마다 갱신됨

                if(array[pivot] == target) {        //만약 타겟과 피봇의 위치가 일치하면
                    return pivot;                   //배열의 인덱스 리턴
                }

                else if(array[pivot] < target) {    //만약 피봇이 타겟보다 작으면
                    left = pivot + 1;               //left는 피봇의 한칸 뒤로 이동
                }

                else {                              //만약 피봇이 타겟보다 크면
                    right = pivot - 1;              //right는 피봇의 한칸 앞으로 이동
                }
            }
            return -1;                              //while을 탈출하고 발견하지 못했을경우 -1반환
        }
        public static void main(String[] args) {
            int[] arr = {1,2,3,4,5,6,7,8,9,10};
            int t = 9;

            System.out.println("idx번호 : " + solution(arr, t));       //idx번호 : 8
        }
    }