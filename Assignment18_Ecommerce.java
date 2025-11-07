package assignment_questions5D4;
import java.util.*;

class Product {
    private int id;
    private String name;
    private int price;

    public Product(int id, String name, int price) {
        this.id = id;
        this.name = name;
        this.price = price;
    }

    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public int getPrice() {
        return price;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (!(obj instanceof Product)) return false;
        Product p = (Product) obj;
        return this.id == p.id;
    }

    @Override
    public int hashCode() {
        return Integer.hashCode(id);
    }

    @Override
    public String toString() {
        return "Product ID: " + id + ", Name: " + name + ", Price: ₹" + price;
    }
}

class Seller {
    private HashSet<Product> productSet = new HashSet<>();

    public void addProduct(Product product) {
        productSet.add(product);
    }

    public HashSet<Product> getProducts() {
        return productSet;
    }
}

class Customer {
    public void orderProducts(HashSet<Product> availableProducts, int[] orderedIds) {
        double totalPrice = 0;
        System.out.println("\nOrdered Products:");
        for (int id : orderedIds) {
            boolean found = false;
            for (Product p : availableProducts) {
                if (p.getId() == id) {
                    System.out.println(p);
                    totalPrice += p.getPrice();
                    found = true;
                    break;
                }
            }
            if (!found) {
                System.out.println("Product ID " + id + " not found.");
            }
        }
        System.out.println("Total Price: ₹" + totalPrice);
    }
}

public class Assignment18_Ecommerce {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Seller seller = new Seller();

        seller.addProduct(new Product(105, "Bluetooth Speaker", 3200));
        seller.addProduct(new Product(106, "Wireless Mouse", 850));
        seller.addProduct(new Product(107, "External Hard Drive", 4800));
        seller.addProduct(new Product(108, "Gaming Keyboard", 2700));


        System.out.println("Available Products:");
        for (Product p : seller.getProducts()) {
            System.out.println(p);
        }

        System.out.print("\nEnter number of products to order: ");
        int count = sc.nextInt();
        int[] orderedProductIds = new int[count];

        for (int i = 0; i < count; i++) {
            System.out.print("Enter Product ID to order: ");
            orderedProductIds[i] = sc.nextInt();
        }

        Customer customer = new Customer();
        customer.orderProducts(seller.getProducts(), orderedProductIds);

        sc.close();
    }
}
