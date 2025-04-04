/**
 * このクラスは、簡単な計算処理を行います。
 */
public class Test {

    /**
     * 2つの整数の和を返します。
     *
     * @param a 最初の整数
     * @param b 2番目の整数
     * @return a と b の合計
     */
    public int add(int a, int b) {
        return a + b;
    }

    /**
     * メインメソッド（実行用）
     * @param args コマンドライン引数
     */
    public static void main(String[] args) {
        Test s = new Test();
        System.out.println("3 + 4 = " + s.add(3, 4));
    }
}
