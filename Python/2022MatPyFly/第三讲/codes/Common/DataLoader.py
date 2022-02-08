from PIL import Image
import numpy as np

class DataLoader:
    # 数据变量
    images = []
    labels = []
    labels_onehot = []
    # 图片数据的首层相对路径，请确保Dataset文件夹恰好位于VScode <当前> 工作空间内！！！
    dataPath = 'Dataset/'
    # 训练数据
    train_images = []
    train_labels = []
    train_labels_onehot = []
    # 验证数据
    validation_images = []
    validation_labels = []
    validation_labels_onehot = []
    # 测试数据
    test_images = []
    test_labels = []
    test_labels_onehot = []
    # 每个标签下的图片数目
    dataCount = 300

    # 加载Mnist数据的函数
    def loadMnistData(self):
        for n in range(10): # 分别加载0-9标签的数据
            for m in range(self.dataCount): # 每个标签下有dataCount个数据
                picPath = self.dataPath + str(n) + '/' + str(m) + '.jpg'    # 图片路径
                image = self.loadPicArray(picPath)  # 读取图片数据
                # 将这次读取的图片数据追加到数据变量的末尾
                # image 和 label 都是二维数组，每一行代表一个样本的数据
                # 每一幅图的数据和其标签在数据变量中的位置是对应的
                label = n
                self.images.append(image)
                self.labels.append(label)
        # TODO 
        # 根据所有标签直接得到所有标签的onehot形式
        # 即得到一个二维数组self.labels_onehot，每一行是一个样本标签的onehot形式
        # 例如某一副图片对应的数字是2，其onehot编码为0010000000；对应数字是3，onehot编码是0001000000
        
        # self.labels_onehot = ...
        

        # TODO 
        # 打乱数据，使用<相同的次序>打乱self.images、self.labels和self.labels_onehot，保证数据仍然对应
        # 提示：https://blog.csdn.net/Strive_For_Future/article/details/81210907
        # ...
        # ...


        # TODO
        # 按比例切割数据，得到：
        # 训练集self.train_images、self.train_labels、self.train_labels_onehot (前65%)
        # 验证集self.validation_images、self.validation_labels、self.validation_labels_onehot(65%到85%)
        # 测试集self.test_images、self.test_labels、self.test_labels_onehot(后15%)
        # ...
        # ...
        # ...


    # 读取图片数据并得到对应的像素值<数组>，像素值是[0,255]，需归一化到0~1
    # 之所以要转变为Ndarray，是因为Ndarray支持更多操作，比如灵活的索引
    def loadPicArray(self, picFilePath):
        picData = Image.open(picFilePath)   # 读取图片
        # TODO 
        # 将picData（二维像素数组）用numpy压缩为一维数组(shape应是（1，784）)，数组元素需归一
        # picArray = ...
        # ...
        return picArray

    def getTrainData(self):
        return self.train_images, self.train_labels, self.train_labels_onehot

    def getValidationData(self):
        return self.validation_images, self.validation_labels, self.validation_labels_onehot

    def getTestData(self):
        return self.test_images, self.test_labels, self.test_labels_onehot