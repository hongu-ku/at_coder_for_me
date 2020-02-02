// 整数の桁数を求める
template <typename T> T GetDigit(T num){
    return to_string(num).length();
}