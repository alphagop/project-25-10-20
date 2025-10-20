#include <stdio.h>
//交换函数
void swap(int* p1, int* p2){
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
    return;
}

//冒泡排序
void bubble_sort(int* nums, int len){
    for(int i=len-1; i>0; i--){
        int count = 0;
        for(int j=0; j<i; j++){
            if(nums[j] > nums[j+1])
            {
                swap(&nums[j], &nums[j+1]);
                count++;
            }
        }
        if(!count){
            break;
        }
    }
    return;
}

//插入排序
void insert_sort(int* nums, int len){
    if (nums == NULL || len <= 1) return; // 边界检查
    for(int i=1; i<len; i++){
        int temp = nums[i];
        int index = i-1;
        while(index>=0 && nums[index]>temp){
            nums[index+1] = nums[index];
            index--;
        }
        nums[index+1] = temp;
    }
}

//选择排序
void select_sort(int* nums, int len){
    if (nums == NULL || len <= 1) return; // 边界检查
    for(int i=0; i<len-1; i++){
        int min = i;
        for(int j=i+1; j<len; j++){
            if(nums[min] > nums[j]){
                min = j;
            }
        }
        swap(&nums[i], &nums[min]);
    }
}

//快速排序——霍尔法
int part_sort_hoare(int* arr, int begin, int end){
    int keyi = begin;
    int left = begin, right = end;

    while(left < right){
        while(left<right && arr[right]>=arr[keyi]){
            right--;
        }
        while(left<right && arr[left]<=arr[keyi]){
            left++;
        }
        if(left < right)
        {
            swap(&arr[left], &arr[right]);
        }
    }
    swap(&arr[keyi], &arr[right]);
    return right;
}

//快速排序——挖坑法
int part_sort_hole(int* arr, int begin, int end){
    int hole = begin;
    int left = begin, right = end;
    int key = arr[hole];

    while(left < right){
        while(left<right && arr[right]>=key) right--;
        arr[hole] = arr[right];
        hole = right;
        while(left<right && arr[left]<=key) left++;
        arr[hole] = arr[left];
        hole = left;
    }
    arr[hole] = key;
    return hole;
}

// 快速排序——双指针法
int part_sort_dualptr(int* arr, int begin, int end) {
    int keyi = begin;
    int slow = begin; // 慢指针：指向已处理序列的末尾
    int fast = begin + 1; // 快指针：遍历整个区间
    
    for (; fast <= end; fast++) {
        if (arr[fast] < arr[keyi]) {
            slow++;
            if (slow != fast) {
                swap(&arr[slow], &arr[fast]);
            }
        }
    }
    swap(&arr[keyi], &arr[slow]);
    return slow;
}
//快速排序主函数
void quick_sort(int* arr, int begin, int end){
    if(arr==NULL || begin>=end) return;
    int mid = part_sort_dualptr(arr, begin, end);
    quick_sort(arr, begin, mid-1);
    quick_sort(arr, mid+1, end);
}

//测试主函数
int main(){
    int nums[] = {3,5,2,1,4};
    int len = sizeof(nums) / sizeof(nums[0]);
    quick_sort(nums, 0, len-1);
    for(int i=0; i<len; i++){
        printf("%d ", nums[i]);
    }
    
    return 0;
}