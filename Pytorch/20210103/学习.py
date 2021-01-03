import torch
import numpy as np

a = torch.randn(2,3)
print(a)
print(a.type())
print(type(a))
print(isinstance(a,torch.FloatTensor))
"""
tensor([[ 0.3496, -0.2872, -0.7142],
        [ 0.4443, -0.2811, -1.2907]])
torch.FloatTensor
<class 'torch.Tensor'>
True
"""

print(isinstance(a,torch.cuda.FloatTensor))
# False
a = a.cuda()
print(isinstance(a,torch.cuda.FloatTensor))
# True

