package assignment_questions5D4;
class Course {
   private int id;
   private String name;
   private double price;
  
   public Course(int id, String name, double price) {
       this.id = id;
       this.name = name;
       this.price = price;
   }
   public int getId() { return id; }
   public String getName() { return name; }
   public double getPrice() { return price; }
}
interface StudentCourse {
   void addCourse(Course course) throws Exception;
   Course[] viewCourses() throws Exception;
   double addFee(Course course) throws Exception;
}
class Semester implements StudentCourse {
   private Course[] courses;
   private int count;
   public Semester(int size) {
       courses = new Course[size];
       count = 0;
   }
   @Override
   public void addCourse(Course course) throws Exception {
       if (course == null) {
           throw new Exception("Course cannot be null");
       }
       if (count >= courses.length) {
           throw new Exception("Course limit reached");
       }
       courses[count++] = course;
   }
   @Override
   public Course[] viewCourses() throws Exception {
       if (count == 0) {
           throw new Exception("No courses added yet");
       }
       Course[] result = new Course[count];
       for (int i = 0; i < count; i++) {
           result[i] = courses[i];
       }
       return result;
   }
   @Override
   public double addFee(Course course) throws Exception {
       if (course == null) {
           throw new Exception("Course is null");
       }
       double fee = course.getPrice();
       if (fee < 1000 || fee > 3000) {
           throw new Exception("Fee must be between 1000 and 3000");
       }
       if (fee > 1500) {
           return fee - (fee * 0.10);  // 10% Discount
       }
       return fee;
   }
}
public class Assignment14_Studentcoursemanagement {
	public static void main(String[] args) {
		 try {
	            StudentCourse sem = new Semester(5);
	            Course c1 = new Course(101, "Data Structures", 2000);
	            Course c2 = new Course(102, "OOPS Java", 1800);
	            Course c3 = new Course(103, "DAA", 3000);
	            sem.addCourse(c1);
	            sem.addCourse(c2);
	            sem.addCourse(c3);
	            Course[] allCourses = sem.viewCourses();
	            for (Course c : allCourses) {
	                System.out.println("Course ID: " + c.getId() + ", Name: " + c.getName() + ", Original Fee: " + c.getPrice());
	                double finalFee = sem.addFee(c);
	                System.out.println("Final Fee after discount (if any): " + finalFee + "\n");
	            }
	        } catch (Exception e) {
	            System.out.println("Error: " + e.getMessage());
	        }
	}
}