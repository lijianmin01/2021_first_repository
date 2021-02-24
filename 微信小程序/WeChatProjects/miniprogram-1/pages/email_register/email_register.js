// pages/email_register/email_register.js
Page({

    /**
     * 页面的初始数据
     */
    data: {
        email: "***",
        code: NaN,
    },
    /**
     * 动态展示用户输入的邮箱号  以及code
     */
    bindTxt: function (e) {
        this.setData({
            email: e.detail.value,
        })
    },
    bindCode: function (e) {
        this.setData({
            code: e.detail.value,
        })
    },
    /**
     * 通过注册
     */
    registerByEmail: function (e) {
        wx.request({
            url: 'url',
            data: {email: this.data.email, code: this.data.code},
            method: "POST",
            success: function (res) {
                console.log(res);
            },
        })
    },
    /**
     * 先检测邮箱格式是否正确，然后在发送验证码
     */
    messageCode: function () {
        // 1796887546@qq.com
        //正则表达式来匹配邮箱
        var reg = /^([a-zA-Z0-9]+[_|\_|\.]?)*[a-zA-Z0-9]+@([a-zA-Z0-9]+[_|\_|\.]?)*[a-zA-Z0-9]+\.[a-zA-Z]{2,3}$/;

        if (!reg.test(this.data.email)) {
            wx.showToast({
                title: '邮箱格式错误',
                icon: "none",//loading/success/none
            })
            return;
        }
        //发送邮箱验证码，登录成功获取jwt 和微信用户信息，保存在globalData和本地存储中
        wx.request({
            url: 'http://127.0.0.1:8000/user/send_code_by_email/',
            data: {email: this.data.email},
            mathod: 'GET',
            dataType: "json",
            success: function (res) {
                if (res.data.status) {
                    //倒计时计数器
                    wx.showToast({
                        title: res.data.message,
                        icon: "none"
                    });
                }
            },
            fail: function (res) {
                console.log("失败")
                console.log(res);
            },
        })
    },
    /**
     * 通过邮箱注册完成提交验证码
     */
    registerByEmail: function () {
        //正则表达式来匹配邮箱
        var reg = /^([a-zA-Z0-9]+[_|\_|\.]?)*[a-zA-Z0-9]+@([a-zA-Z0-9]+[_|\_|\.]?)*[a-zA-Z0-9]+\.[a-zA-Z]{2,3}$/;

        if (!reg.test(this.data.email)) {
            wx.showToast({
                title: '邮箱格式错误',
                icon: "none",//loading/success/none
            })
            return;
        }
        //发送邮箱验证码，登录成功获取jwt 和微信用户信息，保存在globalData和本地存储中
        wx.request({
            url: 'http://127.0.0.1:8000/user/login/',
            data: {email: this.data.email, code: this.data.code},
            mathod: 'POST',
            dataType: "json",
            success: function (res) {
                if (res.data.status) {
                    //倒计时计数器
                    wx.showToast({
                        title: res.data.message, icon: "none"
                    });
                } else {
                    //倒计时计数器
                    wx.showToast({
                        title: res.data.message, icon: "none"
                    });
                }
            },
            fail: function (res) {
                console.log("失败")
                console.log(res);
            },
        })
    },
    /**
     * 生命周期函数--监听页面加载
     */
    onLoad: function (options) {

    },

    /**
     * 生命周期函数--监听页面初次渲染完成
     */
    onReady: function () {

    },

    /**
     * 生命周期函数--监听页面显示
     */
    onShow: function () {

    },

    /**
     * 生命周期函数--监听页面隐藏
     */
    onHide: function () {

    },

    /**
     * 生命周期函数--监听页面卸载
     */
    onUnload: function () {

    },

    /**
     * 页面相关事件处理函数--监听用户下拉动作
     */
    onPullDownRefresh: function () {

    },

    /**
     * 页面上拉触底事件的处理函数
     */
    onReachBottom: function () {

    },

    /**
     * 用户点击右上角分享
     */
    onShareAppMessage: function () {

    }
})