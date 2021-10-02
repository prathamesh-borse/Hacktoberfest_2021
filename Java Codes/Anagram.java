
public class Anagram {

	public static void main(String[] args) {
		String a="cast";
		String b="stack";
		
		boolean visited[]=new boolean[b.length()],is_anagram=false;
		if(a.length() == b.length() ) {
			for(int i =0;i<a.length();i++) {
				for(int j=0;j<b.length();j++) {
					if(a.charAt(i)==b.charAt(j) && !visited[j]) {
						visited[j]=true;
						is_anagram=true;
					}
				}
				if(!is_anagram)
					break;
			}	
		} 
		if(is_anagram) {
			System.out.println("String is anagram ");
		}
		else {
			System.out.println("String is not anagram ");
		}
		
		
	}
}
