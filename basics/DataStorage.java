package basics;

import java.util.HashMap;
import java.util.Map;

public class DataStorage {
    private static final Map<String, Integer> userData = new HashMap<>();

    public static void addUser(String username, int sold) {
        userData.put(username, sold);
    }

    public static int getSold(String username) {
        return userData.getOrDefault(username, 0); 
    }

    public static void updateSold(String username, int newSold) {
        if (userData.containsKey(username)) {
            userData.put(username, newSold);
        } else {
            System.out.println("User '" + username + "' not found.");
        }
    }

    public static void deleteUser(String username) {
        if (userData.containsKey(username)) {
            userData.remove(username);
        } else {
            System.out.println("User '" + username + "' not found.");
        }
    }

    public static void printUsers() {
        if (userData.isEmpty()) {
            System.out.println("No users found.");
        } else {
            System.out.println("List of users:");
            for (Map.Entry<String, Integer> entry : userData.entrySet()) {
                System.out.println("Username: " + entry.getKey() + ", Sold: " + entry.getValue());
            }
        }
    }
}

