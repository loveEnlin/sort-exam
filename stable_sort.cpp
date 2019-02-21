#include <main.cpp>
using namespace std;
void Merge(vector<int> &data, int &start, int &ending, vector<int> &res){
  int is2 = start;
  int ie2 = ending;
  int left_index = is2;
  int left_len = (ie2+is2+1)/2;
  int right_index = is2+left_len;
  int res_index = is2;
  while((left_index < (is2+ left_len)) && (right_index < ie2+1)){
    res[res_index++] = (data[left_index] < data[right_index]) ? data[left_index++] : data[right_index++];
  }
  while(left_index < (is2+ left_len)){
    res[res_index++] = data[left_index++];
  }
  while(right_index <= ie2){
    res[res_index++] = data[right_index++];
  }
//   for(int i =is2; i<ie2;++i){
//     data[i] = res[i];
//   }
}
 
void mergeSort(vector<int> &data, int &start, int &ending, vector<int> &res){
  int is = start;
  int ie = ending;
  int mid = (is+ie+1)*0.5;
  int midr = mid+1;
  if(1 == ie-is){
    if(data[is] > data[ie]){
      Element::swap(data[is], data[ie]);
      res[is] = data[is];
      res[ie] = data[ie];
    }
    return;
  }
  else if(0 == ie-is){
    return;
  }
  else{
    mergeSort(data, is, mid, res); // the left region
    mergeSort(data, midr, ie, res); // the right region
    
    Merge(data, is, ie, res);
//     for(int i = is;i<ie;++i){
//       data[i] = res[i];
//     } 
  }
}
 
int Element::sort_method(){
  int length = data.size();
  int len = data.size()-1;
  vector<int> res;
  res.resize(length);
  mergeSort(data, start, len, res);
}
 
