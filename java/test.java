import java.util.Arrays;

public class test {

  public static void main(String args[]){
    int[] hoge = test();
    System.out.println(hoge[1]);
  }

  private static int[] test(){
    return new int[] {
      12,
        42,
        2
    };
  }
}
