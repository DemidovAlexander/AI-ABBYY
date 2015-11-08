� ������ ����������� ��������� ������������ ���������� AI ��� ���� "�����".

� �������� ������ ��� ��������� API ����������. � ������ �������������� ������, ����������� ������������:
>> IMap

>> IPlayerState

Factory-������� ��� ���:
>> GetPlayerState(int x, int y, int xVelocity, int yVelocity)

��������� �����:
>> GetMap()

�����, ����������� ������� �� inputCells, 
� �������� ������, ���������� ����� ������� _leftFinishPoint, _rightFinishPoint
>> GetMap(const std::vector< std::vector < int > > &inputCells,
>> 	const std::pair< int, int > &_leftFinishPoint,
>> 	const std::pair< int, int > &_rightFinishPoint)

������� ���������:
>> int StrategyFunc(const IMap &_map, const std::vector<std::shared_ptr<IPlayerState>> &_playerStates, int curPlayerPosition);

����� _playerStates - ������ ���������� �� PlayerState ������� �� �������, � curPlayerPosition - ������ ������, ������������ ���.

StrategyFunc ���������� ������� (1-9) ���������� ���� ��� �������� ������.

����������, ������������� �������� ������ ����� ���������� ����� https://github.com/ngc696/PromProg_Race_CardRedactor/issues/1


