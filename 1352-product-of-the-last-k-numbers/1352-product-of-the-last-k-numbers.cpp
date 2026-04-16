class ProductOfNumbers {
public:

    vector<int> prod; 

    ProductOfNumbers() {

    }
    
    void add(int num) {
       prod.push_back(num);
    }
    
    int getProduct(int k) {
        
        int n = prod.size();
        int res = 1;

        for(int i=n-1; i>=n-k; i--){
            res *= prod[i];
        }

        return res;

    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */