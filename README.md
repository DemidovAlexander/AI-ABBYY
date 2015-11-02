В данном репозитории находится динамическая библиотека AI для игры "Гонки".

С командой движка был обговорен API библиотеки. В движок экспортируются классы, описываемые интерфейсами:
>> IMap
>> IPlayerState

Factory-функции для них:
>> GetMap()
>> GetPlayerState(int x, int y, int xVelocity, int yVelocity)

Функция стратегии:
>> StrategyFunc(const IMap &_map, const std::vector<std::shared_ptr<IPlayerState>> &_playerStates, int curPlayerPosition);

Здесь _playerStates представляет из себя вектор указателей на PlayerState каждого из игроков, а curPlayerPosition - индекс игрока, совершающего ход.


Требуется изменение работы AI под установленные командой движка требования, которые можно посмотреть здесь https://github.com/ngc696/PromProg_Race_CardRedactor/issues/1
После доработки алгоритмов соответствующие изменения будут внесены в конструктор карты, вызываемый из factory-функции GetMap().

