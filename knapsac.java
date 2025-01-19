import java.util.Scanner;

public class knapsac {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter number of items: ");
        int n = sc.nextInt();

        Item[] items = new Item[n]; // array of item objects with size n . holds all the items user enters

        String[] itemsInKnapsack = new String[n]; // array to store the items included in the knapsack
        int itemCount = 0; // counter to keep track of how many items are added to the knapsack

        for (int i = 0; i < n; i++) {  // input taken for weight and profit
            System.out.print("Enter weight for item " + (i + 1) + ": ");
            double weight = sc.nextDouble();
            
            System.out.print("Enter profit for item " + (i + 1) + ": ");
            double profit = sc.nextDouble();

            items[i] = new Item(weight, profit);
        }

        bubbleSort(items, n); 

        System.out.print("Enter the total capacity of the knapsack: ");
        double capacity = sc.nextDouble();

        double totalProfit = 0.0;

        for (int i = 0; i < n; i++) {
            if (capacity > 0 && items[i].weight <= capacity) { // if weight of knapsac is >= the weight of item 
                capacity -= items[i].weight;
                totalProfit += items[i].profit;
                itemsInKnapsack[itemCount++] = (i + 1) + "";
            } else if (capacity > 0) { // if weight is > 0 but it is less than the weight of item 
                double fraction = capacity / items[i].weight; // fraction stores the weight of knapsac / item weight
                totalProfit += items[i].profit * fraction; // total profit = total_profit + itemprofit * fraction
                itemsInKnapsack[itemCount++] = (i + 1) + " Partially";
                break;  
            }
        }

        // Display the items included in the knapsack
        System.out.print("Items in knapsack = ");
        for (int i = 0; i < itemCount; i++) {
            System.out.print(itemsInKnapsack[i]);
            if (i < itemCount - 1) {
                System.out.print(", ");
            }
        }
        System.out.println();

        System.out.println("Maximum Profit: " + totalProfit);
        sc.close();
    }

    public static void bubbleSort(Item[] items, int n) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (items[j].ratio < items[j + 1].ratio) {
                    // Swap items[j] and items[j + 1]
                    Item temp = items[j];
                    items[j] = items[j + 1];
                    items[j + 1] = temp;
                }
            }
        }
    }
}

class Item {
    double weight, profit, ratio;

    Item(double weight, double profit) {
        this.weight = weight;
        this.profit = profit;
        this.ratio = Math.round((profit / weight) * 100.0) / 100.0; 
        //Math.round() is a method in Java that rounds a floating-point number to the nearest integer. 
        //*100 to nearest whole number
    }
}




// adding new item ,,, Item myItem = new Item(10.5, 50.0); weight and profit
