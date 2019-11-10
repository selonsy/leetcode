import time
import copy
class Solution:    
    def func1(self, x):
        pass
     
    def getVarLen(self):
        co = self.func1.__code__        
        return co.co_argcount

ori_data = [1]
expect_data = [None]
assert len(ori_data) == len(expect_data),'输入输出数据数量不一致'

s = Solution()
funcs = []
var_len = s.getVarLen() - 1 # exclude self
for key in Solution.__dict__.keys():
    if "func" in key:
        funcs.append(getattr(s, key)) # 反射获取实例化的func
for f in range(len(funcs)):
    func = funcs[f]
    assert func!=None,'func不能为空！'
    begin = time.time() # ToDo：这里的计时有问题，需要改进
    data_length = len(expect_data)
    input_data = copy.deepcopy(ori_data) # 前面的func可能修改测试数据，故深拷贝
    for i in range(data_length):
        if var_len == 1:
            res = func(input_data[i])
            assert res == expect_data[i], "func{0}({3}): expected = {1}, but actually = {2}".format(f+1,expect_data[i], res,input_data[i])
        elif var_len == 2:
            res = func(input_data[i][0],input_data[i][1])
            assert res == expect_data[i], "func{0}({3},{4}): expected = {1}, but actually = {2}".format(f+1,expect_data[i], res,input_data[i][0],input_data[i][1])
        elif var_len == 3:
            res = func(input_data[i][0],input_data[i][1],input_data[i][2])
            assert res == expect_data[i], "func{0}({3},{4},{5}): expected = {1}, but actually = {2}".format(f+1,expect_data[i], res,input_data[i][0],input_data[i][1],input_data[i][2])
        elif var_len == 4:
            res = func(input_data[i][0],input_data[i][1],input_data[i][2],input_data[i][3])
            assert res == expect_data[i], "func{0}({3},{4},{5},{6}): expected = {1}, but actually = {2}".format(f+1,expect_data[i], res,input_data[i][0],input_data[i][1],input_data[i][2],input_data[i][3])
    end = time.time()
    print("func{0} : {1:.4f} ms".format(f+1, (end-begin)*1000/data_length))
print("done")
