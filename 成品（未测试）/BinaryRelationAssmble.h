/*
��Ŀ:����ϵ���ʵ��жϣ�
��������A�ϵĹ�ϵR�ļ��ϱ�ʾ������������A��������ù�ϵ�����ʵ��жϽ����
������ʾ����ϵĹ�ϵ�ľ����жϸù�ϵ�����ʡ�
�Ŷӣ�14�ƿƶ�����ɢ����
��Ա����Т�͡����ı롢ʯ���� �¾��������
�����硢����ϼ������١���Ū�ѡ�����ٻ
*/

/*
��дĿ�꣺��Ƴ����ܺʹ����д�淶�������д�����ֹ�
��д�ˣ���Т��
��дʱ�䣺2015.12.3
�����ļ�������
�����޸ģ�����
*/

/*����淶********1.�����ļ�ͷ�淶
��дĿ�꣺���ļ����ݣ�����ʵ��Ŀ�꣩
��д�ˣ���������
��дʱ�䣺(��.��.��)
�����ļ���(��Ҫһ�������ļ��������޷��ɱ������Զ������ͷ�ļ���)
�����޸ģ�(�޸�ʱ��+�޸�����)   //ÿһ���޸Ļ�һ�У���ʽ��ÿ���ʱ��������ж���
*/

#ifndef BINARY_RELATION_ASSMBLE
#define BINARY_RELATION_ASSMBLE

#include<vector>
#include<string>

using std::vector;
using std::string;

template<typename T>
class BRelation             //��ʾ��Ԫ��ϵ��������<1,2>
{
private:
	T r1;      //��Ԫ��ϵ�е�ǰһ��Ԫ��
	T r2;      //��Ԫ��ϵ�еĺ�һ��Ԫ��

public:
	BRelation(const T & v1, const T & v2)      //���캯��:��V1,V2��ֵ��r1,r2;
	{
		r1 = v1;
		r2 = v2;
	}
	const T & getR1() const { return r1; }     //��ȡ��Ԫ��ϵǰһ��Ԫ�ص�ֵ
	const T & getR2() const { return r2; }     //��ȡ��Ԫ��ϵ��һ��Ԫ�ص�ֵ
	void setR1(const T & v1) { r1 = v1; }    //��v1���õ�һ��Ԫ�ص�ֵ
	void setR2(const T & v2) { r2 = v2; }    //��v2���õڶ���Ԫ�ص�ֵ
};

/*����淶********2.�෽���淶
a.��ȡ��˽�б���ֵʹ��get___��������,�޸���˽�б���ֵʹ��set____����������get��set����Ĳ��ֿ�ͷ��д��ʾ����
b.����(����)�������߶���ͷ�������//ע�ͣ�ע�Ͱ����������ܣ�����˵��������ֵ˵����
c.�����򷽷��в��޸ĵĲ�������constǰ׺���Σ����޸ĵ�����Ķ���ķ�������const��׺��
d.ʹ����ģ���࣬ʹ�÷����ܼ򵥣�����ģ�������ʱ BRelation<T> a; TΪϣ�����������е�T�滻������
���ⶨ��ģ���෽���ĸ�ʽ����setR1()Ϊ����
template<typename T>
void BRelation<T>::setR1(const T & v1){  }  ��ǰһ�м���template<typename T>����������ǰ�������������������::
e.����ʹ��Ӣ�ĵ���,�������ͷ�����ͷ��ĸСд����ʹ���м�����Ĵ�д��ĸ�ֿ����ʣ���������ĸ��д��
f.���������ܼ�ʹȱ��ע��Ҳ��һ�ۿ������ܣ�
*/

template<typename T>
class BinaryRelationAssmble
{
private:
	vector<T> father;   //����������Ŀ�еļ���A
	vector< BRelation<T> > relation;  //��Ԫ��ϵ�ļ���
	vector< vector<int> >  matrix;  //��ϵ����
	/*���ǵ�ָ��ʹ��������Ĳ������ϣ��Լ��������Ϻ�ĸ��ӹ��ϣ�����ʹ��STL�е���򵥵�����vector��ʵ�ֶ�̬���飬
	  ��ԭ�����������ݽṹ�е����Ա�ɱ����飬֧��ʹ��[]�����ڲ�Ԫ�أ�vector<T>�е�T��ʾ��̬�����е�Ԫ�����ͣ�
	  ��Ҳ��һ��ģ���࣬�����Զ���չ�����⣬vector���кܶ���ڲ����ķ��������罫Ԫ�ؼ�������β������ɾ��Ԫ�صȵȡ�
	  vector����෽���������в���C++�����ĵ�������������Ѱ������ϣ�ʹ�û��ǽϼ򵥵�
	*/


	/*����淶********3.ʵ�ֹ淶
	  a.�ַ�������ͳһʹ��string���Ͷ������ַ����飻
	  b.��̬����ʹ��vector,�����õ�ָ��ĵط��������ۣ�
	  c.��ָ��ͳһʹ��NULL��
	*/

	/*������ϼ������������������A�仯ʱ��ϵ����matrix�ı仯�������ݱ仯���ӻ�ɾ������*/
	void whenFatherChange();  //��ʹ��vector���erase()����ɾ����resize()���������У�ע�����Ƕ�ά���飬���ж�Ҫ�޸�

	/*(�¾���)������������Matrix������Ԫ����0*/
	void setMatrixZero();

	/*(��Ū��)���ö�ά����matrix[i][j]��ֵ,����Ϊֵvalue*/
	void setMatrixValue(int i, int j, int value = 0);

	/* (������)�������ĳ˻�����matrixp ��ʾ��˻�*/
	void matrixProduct(vector< vector<int> > &  matrixp);

public:
	/*(�¾���)���Ԫ��el������A*/
	void add_father(const T & el);
	/*���¾����Ԫ��e1,e2Ϊ<el,e2>��ӵ���Ԫ��ϵ����relation*/
	void add_relation(const T & e1, const T & e2);

	/*(�����)��ϵ����ת��Ϊ��ϵ����relationתΪ��matrix��ʾ��
	��father���϶�ӦԪ�ص��±���Ϊ��ϵ������Ϊ�������б�־
	��  a b c
	a 0 1 0
	b 0 0 1
	c 1 1 0
	abc�洢��father�����У��ʿ�����father[0]��father[1]father[2]�ֱ��ʾ
	�������һ�б�ʾΪmatrix[0][0]��matri[0][1]��matrix[0][2],ֵΪ0��1��0;
	����Ϊmatrix��ά��̬����洢��ϵ����ķ�ʽ
	*/
	void relationTOmatrix();  //ps���м����to�Ĵ�д,����T����
							  /*(�����)��ϵ����ת��Ϊ��ϵ����(matrixת��Ϊrelation)*/
	void matrixTOrelation();


	/*(��Ū��)��ȡmatrix[i][j]ֵ*/
	int getMatrixValue(int i, int j);
	/*(��Ū��)��ȡ����A����father��Ԫ����Ŀ*/
	int getFatherLength();
	/*(��Ū��)��ȡ��Ԫ��ϵ����relation��Ԫ����Ŀ*/
	int getRelationLength();
	/*(��Ū��)����һ��i��j�еľ���*/
	bool inputMatrix();   //����ɹ�����true������ʧ�ܷ���false�����Բ�һ��cin������ʧ�ܵ�һЩ��������ǣ�

	//��ϵ�ж�һ���Ծ���Ϊ�����������жϺ�����һ���ȵ���relationTOmatrix()����Ԫ��ϵת��Ϊ����
	/*(����ϼ)�ж϶����Ƿ������Է���,���㷵��true,�����㷵��false*/
	bool isReflexive();
	/*(����ϼ)�ж϶����Ƿ����㷴�Է���,���㷵��true,�����㷵��false*/
	bool isIrreflexive();
	/*(������)�ж϶����Ƿ�����Գ���,���㷵��true,�����㷵��false*/
	bool isSymmetric();
	/*(������)�ж϶����Ƿ����㷴�Գ���,���㷵��true,�����㷵��false*/
	bool isAntisymmetric();
	/*(������)�ж϶����Ƿ����㴫����,���㷵��true,�����㷵��false*/
	bool isTransitive();

	/*(��Т��)main�����Ϳ���̨�����˵�*/

	/*��ո����Ͷ�Ԫ��ϵ���ϡ�����*/
	void clear();
	
	/*�жϸ������Ԫ��ϵ�������Ƿ��п�*/
	bool has_empty();

	/*(ʯ��)�������Ԫ��*/
	void print_father();
	/*(ʯ��)�����ϵ����*/
	void print_relation();
	/*(ʯ��)�����ϵ����(��ѡ)*/
	void print_matrix();
};


/*����淶********4.��д�淶
a.��������ظ����ظ����о�����ѭ�����棬�ظ��Ŀ龡���ú������棬Ϊ�ų������ṩ����
b.main������д������ʹ�ø�λ��д�Ĺ��з�������λ�ڱ�д����������Ҳ���Զ��������Ƴ��Ĺ��ܷ�����ʵ��
c.����˼·Ϊ֧�־�������͹�ϵ���룬ת��Ϊ��ϵ������ж��Ƿ�������Ӧ����;
*/

/*������������Matrix������Ԫ����0*/
template<typename T>
void BinaryRelationAssmble<T>::setMatrixZero() {//������������Matrix������Ԫ����0
	int m = getFatherLength();
	for (int i = 0; i<m; i++)//��һ��ѭ��; iΪ�У�mΪA�������е�Ԫ����Ŀ��ʹ��_getFatherLength()��ã�
		for (int j = 0; j<m; j++)//�ڶ���ѭ����jΪ��
		{
			matrix[i][j] = 0;
		}
}

/*���Ԫ��el������A*/
template<typename T>
void BinaryRelationAssmble<T>::add_father(const	T & e1) {//���Ԫ��el������A

	father.push_back(e1);//���Ԫ��e1

}

/*��Ԫ��e1,e2Ϊ<el,e2>��ӵ���Ԫ��ϵ����relation*/
template<typename T>
void BinaryRelationAssmble<T>::add_relation(const T & e1, const T & e2)//��Ԫ��e1,e2Ϊ<el,e2>��ӵ���Ԫ��ϵ����relation
{
	BRelation<T>  r(e1, e2);
	relation.push_back(r);
}

/*���ö�ά����matrix[i][j]��ֵ,����Ϊֵvalue*/
template<typename T>
void BinaryRelationAssmble<T>::setMatrixValue(int i, int j, int value = 0)
{
	matrix[i][j] = value;
}


/*��ȡmatrix[i][j]ֵ*/
template<typename T>
int BinaryRelationAssmble<T>::getMatrixValue(int i, int j)
{
	return matrix[i][j];
}

/*��ȡ����A����father��Ԫ����Ŀ*/
template<typename T>
int BinaryRelationAssmble<T>::getFatherLength()
{
	return father.size();
}

/*��ȡ��Ԫ��ϵ����relation��Ԫ����Ŀ*/
template<typename T>
int BinaryRelationAssmble<T>::getRelationLength()
{
	return relation.size();
}


/*����һ����ϵ����*/
template<typename T>
bool BinaryRelationAssmble<T>::inputMatrix()  //����ɹ�����true������ʧ�ܷ���false�����Բ�һ��cin������ʧ�ܵ�һЩ��������ǣ�
{
	int  i, j;
	i = j = father.size();
	matrix.resize(i);
	int I, J;
	for (I = 0; I<i; I++)
		for (J = 0; J<j; J++)
		{
			int temp;
			cin >> temp;
			matrix[I].push_back(temp);
			if (cin.fail())
				return false;
		};
	return true;
}

//��ϵ����ת��Ϊ��ϵ������ж�
template <typename T>
void BinaryRelationAssmble<T>::relationTOmatrix()
{
	/*int fnum = getFatherLength();//���������������������fnum
	int a, i, j, k;
	matrix.resize(fnum);
	for (a = 0; a<frum; a++)
		matrix[a].resize(fnum);
	*/
	int fnum = getFatherLength();
	int  i, j, k;
	whenFatherChange();
	setMatrixZero();
	for (k = 0; k < getRelationLength(); k++)//����ϵ���ϵ���Ŀ��k����ʾ
	{
		for (j = 0; j < fnum; j++)
		{
			for (i = 0; i < fnum; i++)
			{
				if (father[i] == relation[k].getR1() && father[j] == relation[k].getR2())
					matrix[i][j] = 1;
			}
		}
	}

}

//��ϵ����ת��Ϊ��ϵ���ϵ��ж�
template <typename T>
void BinaryRelationAssmble<T>::matrixTOrelation()
{
	int fnum = getFatherLength();
	relation.clear();//�������
	int i, j;
	for (i = 0; i < fnum; i++)
	{
		for (j = 0; j < fnum; j++)
		{
			if (matrix[i][j] == 1)
			{
				BRelation <T> a(father[i], father[j]);
				relation.push_back(a);
			}
			//else
				//cout << "��ϵ������" << endl;
		}
	}
}

template<typename T>
void BinaryRelationAssmble<T>::print_father()
{
	int i;
	cout << "{";
	for (i = 0; i < father.size() - 1; i++)
		cout << father[i] << ",";
	cout << father[i] << "}";
}

template<typename T>
void BinaryRelationAssmble<T>::print_matrix()
{
	int i, j;
	for (i = 0; i < getFatherLength(); i++)
	{
		for (j = 0; j < getFatherLength(); j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}

template<typename T>
void BinaryRelationAssmble<T>::print_relation()
{
	int i;
	cout << "{" ;
	for (i = 0; i<relation.size() - 1; i++)
		cout << "<" << relation[i].getR1() << "," << relation[i].getR2() << ">" << ",";
	cout << "<" << relation[i].getR1() << "," << relation[i].getR2() << ">";
	cout << "}" << endl;
}

/*(����ϼ)�������A�仯ʱ��ϵ����matrix�ı仯�������ݱ仯���ӻ�ɾ������*/
template<typename T>
void  BinaryRelationAssmble<T>::whenFatherChange()
{
	int i;
	int fnum = getFatherLength();					 // ������AԪ���������������������������fnum;
	matrix.resize(fnum);
	for (i = 0; i<fnum; i++)
		matrix[i].resize(fnum);
}

/*(����ϼ)�ж϶����Ƿ������Է���,���㷵��true,�����㷵��false*/
template<typename T>
bool  BinaryRelationAssmble<T>::isReflexive()
{
	int i;
	int fnum = getFatherLength();					 // ������AԪ���������������������������fnum;
	for (i = 0; i < fnum; i++)
		if (matrix[i][i] != 1)   //�ж����Խ�����Ԫ���Ƿ�Ϊ1
			return false;
	return true;
}

/*(����ϼ)�ж϶����Ƿ����㷴�Է���,���㷵��true,�����㷵��false*/
template<typename T>
bool  BinaryRelationAssmble<T>::isIrreflexive()
{
	int i;
	int fnum = getFatherLength();
	for (i = 0; i < fnum; i++)
		if (matrix[i][i] == 1) //�ж����Խ�����Ԫ���Ƿ�Ϊ1
			return false;
	return true;
}

/*(������)�ж϶����Ƿ�����Գ���,���㷵��true,�����㷵��false*/
template<typename T>
bool  BinaryRelationAssmble<T>::isSymmetric()
{
	int i, j;

	int fnum = getFatherLength();					 // ������AԪ���������������������������fnum;
	for (i = 0; i < fnum; i++)
		for (j = i; j < fnum; j++)					//�Ծ����ϰ벿�ֽ��б����жϣ�matrix[i][j]�Գ�λ���Ƿ��������  
			if (matrix[i][j] != matrix[j][i])
				return false;
	return true;
}

/*(������)�ж϶����Ƿ����㷴�Գ���,���㷵��true,�����㷵��false*/
template<typename T>
bool  BinaryRelationAssmble<T>::isAntisymmetric()
{
	int i, j;
	int fnum = getFatherLength();
	for (i = 0; i < fnum; i++)
		for (j = i; j < fnum; j++)						//�Ծ����ϰ벿�ֽ��б����жϣ�matrix[i][j]�Գ�λ���Ƿ��������  
			if ((matrix[i][j] == 1) && (matrix[j][i] == 1))
				if (i != j)								// �ж϶Գ�λ����ȵ������Ƿ������Խ�����
					return false;
	return true;
}


/* �������ĳ˻�����matrixp ��ʾ��˻�*/
template<typename T>
void  BinaryRelationAssmble<T>::matrixProduct(vector< vector<int> > &  matrixp)
{
	int i, k, j;   // �������
	int temp = 0;	   //  ���ڴ�ų˻������ֵ

	int fnum = getFatherLength();                  // ��fnum ��ž�����к���  
													  /*  Ϊ�˻���������С������ʼ��Ϊ0*/
	matrixp.resize(fnum);
	for (i = 0; i < fnum; i++)
		matrixp[i].resize(fnum, 0);
	/* ���г˻�����*/
	for (i = 0; i < fnum; i++)
		for (j = 0; j < fnum; j++)
		{
			temp = 0;
			for (k = 0; k < fnum; k++)                 // ��˻�������Ӧ���꣨i,j)��ֵ       
				temp += getMatrixValue(i, k) * getMatrixValue(k, j);
			matrixp[i][j] = temp;
			/*if (temp != 0)                             //���temp��Ϊ0���򽫳˻�����������Ӧ��ֵ��Ϊ1
				matrixp[i][j] = 1;
			else
				matrixp[i][j] = 0;*/
		}

}

/*(������)�ж϶����Ƿ����㴫����,���㷵��true,�����㷵��false*/
template<typename T>
bool  BinaryRelationAssmble<T>::isTransitive()
{
	int fnum = getFatherLength();           //  ��fnum ��ž�����к���
	vector< vector<int> >  matrixp;
	matrixProduct(matrixp);                                   // ֱ�ӵ��ã�����Ҫ���ݲ������˻�����Ϊȫ�ֱ���

	int j, i;
	for (i = 0; i < fnum; i++)
		for (j = 0; j < fnum; j++)
		{
			if (matrixp[i][j] == 1)						   // �ҳ��˻������У�ֵΪ1 ��λ��
			{
				if (matrix[i][j] != 1)						// �ж�matrix�����ж�Ӧ��λ���Ƿ�Ϊ1,��Ϊ1 ���򴫵�
					return false;
			}
		}
	return  true;                                           // ����β��裬˵�������Ǵ��ݵ�
}

/*��ո����Ͷ�Ԫ��ϵ���ϡ�����*/
template<typename T>
void BinaryRelationAssmble<T>::clear()
{
	father.clear();
	relation.clear();
	setMatrixZero();
}

/*�жϸ������Ԫ��ϵ�������Ƿ��п�*/
template<typename T>
bool BinaryRelationAssmble<T>::has_empty()
{
	return father.empty() || relation.empty();
}

#endif


