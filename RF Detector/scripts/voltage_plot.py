import matplotlib.pyplot as plt
voltage_data = open('values.txt').read().splitlines()

plt.ylabel('Voltage (V)')
plt.plot(voltage_data)
plt.ylim(0.8, 1.3)

plt.show()