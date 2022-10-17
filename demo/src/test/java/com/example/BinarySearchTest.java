package com.example;

import org.junit.Assert;
import org.junit.Test;

public class BinarySearchTest {

    @Test
    public void testBSearch() {
        BinarySearch ob = new BinarySearch();
        int arr[] = { 2, 3, 4, 10, 40 };
        int n = arr.length;
        int x = 40;
        int result = ob.binarySearch(arr, 0, n - 1, x);
        
        Assert.assertEquals(5, result);
    }
}
