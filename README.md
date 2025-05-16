# 🛡 Battle Platform System (ROS 2)

Це ROS 2-проєкт, що моделює мережу автономних бойових платформ, які виявляють, супроводжують і уражають повітряні або наземні цілі за допомогою розподілених сенсорів і виконавчих механізмів.

## 🧩 Основні компоненти

- `scanner_platform` — LiDAR-сенсори, виявлення цілей.
- `combat_platform` — локальний трекер, система вогню, наведення.
- `central_hub` — командний центр, маршрутизація цілей.
- `operator_interface` — RViz або GUI для людини-оператора.
- `positioning` — координатна сітка (map / base_link).
- `common_msgs` — повідомлення та сервіси системи.

## 🚀 Запуск

```bash
cd ~/battle_ws
colcon build --symlink-install
source install/setup.bash
ros2 pkg list
```
## 📄 Документація

- **Use Cases:** [docs/use_cases.md](docs/use_cases.md)
- **Архітектура:** [docs/architecture_overview.png](docs/architecture_overview.png)
