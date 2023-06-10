double getMedian(vector<int>& freq, int d) {
    int count = 0;
    if (d % 2 == 0) {
        int m1 = -1, m2 = -1;
        for (int i = 0; i < freq.size(); i++) {
            count += freq[i];
            if (m1 == -1 && count >= d / 2)
                m1 = i;
            if (m2 == -1 && count >= d / 2 + 1)
                m2 = i;
            if (m1 != -1 && m2 != -1)
                break;
        }
        return (m1 + m2) / 2.0;
    } else {
        for (int i = 0; i < freq.size(); i++) {
            count += freq[i];
            if (count > d / 2)
                return i;
        }
    }
    return -1; 
}
    


int activityNotifications(vector<int>& expenditure, int d) {
    int total_notifications = 0;
    
    // Create an array to store the frequency of each expenditure
    vector<int> array_count(201, 0); 
    // Update the frequency array
    for (int i = 0; i < d; i++)
        array_count[expenditure[i]]++;
    
    for(int i=0 ; i< expenditure.size();i++){
        if(i>=d){
            double median = getMedian(array_count, d);
            if(expenditure[i] >= 2* median){
                total_notifications++;
            }
            array_count[expenditure[i-d]]--;
        
        array_count[expenditure[i]]++;
        }
    }
    return total_notifications;

}
