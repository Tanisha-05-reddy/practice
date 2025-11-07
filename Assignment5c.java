package javaD4;
public class Assignment5c {

	public static void main(String[] args) {
		String[] arr1 = {"hello","hai","bye","hi"};
		String[] arr2 = {"hello","bye","run","file"};
		
		System.out.println("Common elements are: ");
		for(int i=0;i<arr1.length;i++) {
			for(int j=0;j<arr2.length;j++) {
				if(arr1[i]==arr2[j]) {
					System.out.println(arr1[i]);
				}
			}
		}

	}

}
