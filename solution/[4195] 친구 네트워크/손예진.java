package cns;

import java.util.*;

/* <idea>
 * 1. 같은 네트워크에 속하냐 == 같은 집합에 속하냐 == Union-Find에서 부모가 같냐
 * 2. 부모 노드에 집합 크기 저장해두기 
 * <difficulty>
 * 1. Find에서 "parents.get(a) == null"일 때 부모를 자기 자신으로 초기화 시켜줘야되는데 안 해줌
 * -> (a, b), (b, a) 나오면 ..??
 * 2. 어차피 Union하는 과정에서 중복이 없다는 점을 간과
 * -> Map<String, HashSet<String>> child으로 구성했다가 메모리 초과 발생
 * */

public class test_4195{
	//main 밖에 선언되는 함수와 변수는 반드시 static
    static Map<String, String> parents;
    static Map<String, Integer> child;
    static int F;
    static void Union(String a, String b){
    	String pa, pb;
    	pa = Find(a);
    	pb = Find(b);
    	if(!pa.equals(pb)) {	//pb의 부모 => pa
	    	System.out.println(a + " " + b + " " + pa + " " + pb);
    		parents.put(pb, pa);
	    	Integer ca = child.get(pa);
	    	Integer cb = child.get(pb);
	    	child.put(pa, ca + cb);
    	}
    }
    
    static String Find(String a){
    	if(parents.get(a) == null) {
    		parents.put(a, a);
    		return a;
    	}
    	if(parents.get(a) == a)
    		return a;
    	String pa = Find(parents.get(a));
    	parents.put(a, pa);
    	return pa;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T;
        T = sc.nextInt();
        while(T-- > 0){	//자바 조건문은 반드시 boolean -> int 절대 안됨!
            F = sc.nextInt();
            parents =  new HashMap<>();
            child =  new HashMap<>();
            for(int i = 0; i < F; i++){
                String a, b;
                a = sc.next();
                b = sc.next();
                if(child.get(a) == null) {
                	child.put(a, 1);
                }
                if(child.get(b) == null) {
                	child.put(b, 1);
                }
                Union(a, b);
                String p = Find(a);
                System.out.println(child.get(p));
            }
        }
    }
}
