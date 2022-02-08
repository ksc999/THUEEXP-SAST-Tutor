# 导入自定义的数据加载包
from Common.DataLoader import DataLoader
from scipy.special import expit
import numpy as np

#定义逻辑回归类
class LogisticRegression:
    
    w = None    # 权重

    # 训练函数
    # data_x: 训练数据集合
    # data_y: 训练数据标签集合，需要onehot形式
    # learning_rate: 学习速率
    # iteration_count: 迭代次数
    def train(self, data_x, data_y, learning_rate, iteration_count = 100):
        # data_x的shape为(数据条数 * 每条数据的宽度)
        # data_y的shape为(数据条数 * 分类标签个数)
        data_x_width = len(data_x[0])   # 每条数据宽度
        dataCount = len(data_y)         # 数据条数
        classCount = len(data_y[0])     # 分类标签个数

        # TODO
        # 请用全零矩阵初始化权重数组self.w，其shape为（data_x_width + 1, classCount），+1对应后面增加的偏置项
        # self.w = ...           

        # TODO
        # 请用np.insert（）函数在data_x每一行的末尾增加偏置（values = 1）
        # data_x = ...
        # 请用全零矩阵j_w存储损失结果,shape为（iteration_count, classCount）
        # j_w = ...               

        for k in range(classCount):                                     # 考察每一种数字
            real_y = data_y[:, k].reshape((dataCount, 1))               # 从onehot数组获取二分类标签真值（0或1）向量
            for j in range(iteration_count):                            # 多次训练
                w_temp = self.w[:, k].reshape((data_x_width + 1, 1))    # 获取<当前>权重中对应数字k的权重向量
                h_w = expit(np.dot(data_x, w_temp))                     # 计算当前权重下得到的分类概率
                j_w[j, k] = (np.dot(np.log(h_w).T, real_y) + np.dot((1 - real_y).T, np.log(1 - h_w))) / (-dataCount) #计算损失
                w_temp = w_temp + learning_rate * np.dot(data_x.T, (real_y - h_w)) # 梯度下降，自动调节权重
                self.w[:, k] = w_temp.reshape((data_x_width+1,))         # 更新对应数字k的权重向量
        
    # 预测函数
    # data_x: 训练数据集合
    # data_y: 训练数据标签集合，需要采用onehot形式
    def predict(self, data_x, data_y):
        data_x_width = len(data_x[0])   # 每条数据宽度
        dataCount = len(data_y)         # 数据条数
        classCount = len(data_y[0])     # 分类标签个数
        
        errorCount = 0 # 预测错误的数量

        # TODO
        # data_x每行末尾增加偏置值 1
        # data_x = ...  # 数据中增加偏置项


        h_w = expit(np.dot(data_x, self.w))                         # 计算分类概率
        h_w_max_index = h_w.argmax(axis=1)                          # 获取每一行最大概率的索引，得到一个向量
        for i in range(dataCount):                                  # 统计预测错误的数量
            if data_y[i][h_w_max_index[i]] != 1:
                errorCount += 1

        error_rate = float(errorCount) / dataCount                  # 计算错误率

        return error_rate, h_w_max_index                            # 返回错误率和预测结果


if __name__ == '__main__':

    # 加载 Mnist数据
    print('Loading Mnist data...')
    dataLoader = DataLoader()
    dataLoader.loadMnistData()

    #获取训练、验证和测试数据
    train_images, train_labels, train_labels_onehot = dataLoader.getTrainData()
    validation_images, validation_labels, validation_labels_onehot = dataLoader.getValidationData()
    test_images, test_labels, test_labels_onehot = dataLoader.getTestData()


    image_width = len(train_images[0])
    class_count = len(train_labels_onehot[0])

    learning_rate = 0.01    # LogisticRegression的学习速率参数
    best_lr = None
    error_rate_min = 1

    print('Start training...')
    while learning_rate > 0.00001:                                                   # 训练结束条件，参数可调
        lr = LogisticRegression()                                                    # 初始化逻辑回归对象
        lr.train(train_images, train_labels_onehot, learning_rate, 100)              # 使用训练集训练，训练次数可调
        error_rate, _ = lr.predict(validation_images, validation_labels_onehot)      # 使用验证集预测
        print('Validation error rate: ', 100 * error_rate, '%', sep='')
        if error_rate < error_rate_min:                                              # 保存较优的<模型>
            error_rate_min = error_rate
            best_lr = lr
        learning_rate = learning_rate / 2                                            # 学习率减半
    print('Train done')

    error_rate, _ = best_lr.predict(test_images, test_labels_onehot)                # 使用最佳模型在测试集上预测
    print('Test error rate: ', 100 * error_rate, '%', sep='')

