� ������ ����������� ��������� ������������ ���������� AI ��� ���� "�����".

� �������� ������ ��� ��������� API ����������. � ������ �������������� ������, ����������� ������������:
>> IMap
>> IPlayerState

Factory-������� ��� ���:
>> GetMap()
>> GetPlayerState(int x, int y, int xVelocity, int yVelocity)

������� ���������:
>> StrategyFunc(const IMap &_map, const std::vector<std::shared_ptr<IPlayerState>> &_playerStates, int curPlayerPosition);

����� _playerStates ������������ �� ���� ������ ���������� �� PlayerState ������� �� �������, � curPlayerPosition - ������ ������, ������������ ���.


��������� ��������� ������ AI ��� ������������� �������� ������ ����������, ������� ����� ���������� ����� https://github.com/ngc696/PromProg_Race_CardRedactor/issues/1
����� ��������� ���������� ��������������� ��������� ����� ������� � ����������� �����, ���������� �� factory-������� GetMap().

