
#pragma once
#include <QVector>
class AlgorithmClass
{
public:
	AlgorithmClass() {}
	~AlgorithmClass() {}
	template <class T>
	void Combination(QVector<T>& returnValue,QVector<T>& ValueRange,int selectNum); 
private:

};
template <class T>
void AlgorithmClass::Combination(QVector<T>& returnValue, QVector<T>& ValueRange, int selectNum)
{
	QVector<T> ValueRangeTemp = ValueRange;
	int numMax = ValueRange.size();
	int numRange1 = numMax;
	while (numRange1>(numMax - selectNum))
	{
		int selectedID = qrand() % (numRange1 - 1);
		returnValue.append(ValueRangeTemp[selectedID]);
		//删除已经选过的变量
		for (int i = numRange1 - 1; i >= 0; i--)
			if (i == selectedID)
				ValueRangeTemp.erase(ValueRangeTemp.begin() + i);
		numRange1--;
	}
	qSort(returnValue.begin(), returnValue.end());
}
