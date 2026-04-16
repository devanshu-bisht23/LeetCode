class ProductOfNumbers {
public:

    vector<int> prod; 

    ProductOfNumbers() {
        prod.push_back(1);
    }
    
    void add(int num) {
       if(num==0){
        prod.clear();
        prod.push_back(1);
       }else{
        prod.push_back(prod.back() * num);
       }
    }
    
    int getProduct(int k) {
        int n = prod.size();

        if(k >= n) return 0;

        return prod[n - 1] / prod[n - k - 1];

    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */