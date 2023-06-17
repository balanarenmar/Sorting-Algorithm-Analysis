# Sorting-Algorithm-Analysis
This program uses different sorting algorithms (Insertion Sort, Merge sort, Quicksort, Heapsort) to  sort 2 kinds of input:
1. N number if **unordered** and randomly generated integers. 
2. N number of **ordered** set of integers.

After sorting the input set, the efficiency of each algorithms are measured by their computing time.

---

## **Output Analysis**
<br>
<table>
<tr><th> <b>Average running time for a random input array</b> </th></tr>
<tr><td>

| N | Insertion Sort | Merge Sort | Quicksort | Heapsort | 
|--:|--:|--:|--:|--:|
| 10 | 0 | 0 | 0 | 0 |
| 100 | 0 | 0 | 0 | 0 |
| 1,000 | 0 | 0 | 0 | 0 |
| 10,000 | 0.1472  | 0.0082 | 0 | 0.0032 |
| 100,000 | 13.5048 | 13.5048 | 0.0192 | 0.0412 |

</td></tr>
</table><br>


<table>
<tr><th> <b>Average running time for a sorted input array</b> </th></tr>
<tr><td>

| N | Insertion Sort | Merge Sort | Quicksort | Heapsort | 
|--:|--:|--:|--:|--:|
| 10 | 0 | 0 | 0 | 0 |
| 100 | 0 | 0 | 0 | 0 |
| 1,000 | 0 | 0.0024 | 0.0112 | 0.0002 |
| 10,000 | 0  | 0.0042 | 0.5360 | 0.0030 |
| 100,000 | 0.0008 | 0.0440 | 0.044 | 0.0346 |

</td></tr>
</table><br>

**The values presented are in time seconds.*

