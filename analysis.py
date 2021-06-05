# import numpy as np
# import matplotlib.pyplot as plt
# import pandas as pd
# import collections as cl

plt.style.use('dark_background')
df = pd.read_csv("pAnalysis.csv")

gen = df["Gender"].tolist()
age = df["Age"].tolist()
taluk= df["Taluk"].tolist()
symp = df["Symptom"].tolist()

counterAge = cl.Counter(age)
counterGen = cl.Counter(gen)
counterTal = cl.Counter(taluk)
counterSymp = cl.Counter(symp)


ageFreq=counterAge.values()
ageVal=counterAge.keys()
TalFreq=counterTal.values()
TalVal=counterTal.keys()
SympFreq = counterSymp.values()
SympVal = counterSymp.keys()
freq = counterGen.values()
var= counterGen.keys()


# fig, axes = plt.subplots(4, 4, figsize=(12, 8))

# fig = 
# fig,plt.tight_layout()
plt.subplot(2,2,1)
plt.title("Covid 19 Taluk wise Distribution",color="#b0ece2",fontsize=10)
plt.pie(TalFreq,labels=TalVal)
plt.subplot(2,2,3)
plt.title("Case Age Ratio",color="#b0ece2",fontsize=10)
plt.bar(range(len(counterAge)), list(counterAge.values()), align='center')
plt.xticks(range(len(counterAge)), list(counterAge.keys()))
plt.subplot(2,2,2)
plt.title("Male-Female Ratio",color="#b0ece2",fontsize=10)
plt.pie(freq, labels = var)
plt.subplot(2,2,4)
plt.title("Major Symptoms Chart",color="#b0ece2",fontsize=10)
plt.bar(range(len(counterSymp)), list(counterSymp.values()), align='center')
plt.xticks(range(len(counterSymp)), list(counterSymp.keys()))
mng = plt.get_current_fig_manager()
mng.resize(*mng.window.maxsize())
plt.show()
