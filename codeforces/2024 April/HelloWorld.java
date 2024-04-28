import java.util.*;

public class HelloWorld{

     public static void main(String []args){
        Scanner s = new Scanner(System.in);
        int t;
        t = s.nextInt();
        while(t-->0){
            String s1;
            String s2;
            s1 = s.next();
            s2 = s.next(); 

            int flag = 0;

            char[] arr1 = s1.toCharArray(); 
            char[] arr2 = s2.toCharArray(); 

            for(int i=0;i<s2.length();i++){
                if (arr1[i] == arr2[i])
        {
            continue;
        }
        if (flag == 0 && arr1[i] > arr2[i])
        {
            flag = 1;
            continue;
        }
        if (flag == 0 && arr1[i] < arr2[i])
        {

            char temp = arr1[i];
            arr1[i] = arr2[i];
            arr2[i] = temp;
            flag = 1;
            continue;
        }
        if (flag == 1)
        {
            if (arr1[i] > arr2[i])
            {
                char temp = arr1[i];
                arr1[i] = arr2[i];
                arr2[i] = temp;
            }
        }

            }
            for(int i=0;i<s1.length();i++){
                System.out.print(arr1[i]);
            }
            System.out.println();
            for(int i=0;i<s2.length();i++){
                System.out.print(arr2[i]);
            }
            System.out.println();
        
        }
     }
}