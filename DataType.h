enum Comparison {
	GREATER,
	LESS,
	EQUAL
};
class DataType {
public:
	explicit DataType(int value);

	Comparison compareTo(DataType &item);
	int getValue() const;

private:
	int value;




};
