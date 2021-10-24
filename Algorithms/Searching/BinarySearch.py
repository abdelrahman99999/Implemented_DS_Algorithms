def binary_search(list ,item):
    L=0
    R=len(list)-1
    while R>=L :
        mid=int((R+L)/2)
        if list[mid]==item :
            return mid
        if item < list[item]:
             R=mid-1
        else :
             L=mid+1
    return None
    
my_list=[1,3,5,7,9]

print(binary_search(my_list,5))
print(binary_search(my_list,-1))
