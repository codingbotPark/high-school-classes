const Sequelize = require('sequelize');

class Hashtag extends Sequelize.Model {
  static initiate(sequelize) {
    Hashtag.init({
      title: {
        type: Sequelize.STRING(15),
        allowNull: false,
        unique: true,
      },
    }, {
      sequelize,
      timestamps: true,
      underscored: false,
      modelName: 'Hashtag',
      tableName: 'hashtags',
      paranoid: false,
      charset: 'utf8mb4',
      collate: 'utf8mb4_general_ci',
    });
  }

  static associate(db) {
    // through = maping table 이름을 만들어 준다
    db.Hashtag.belongsToMany(db.Post, { through: 'PostHashtag' });
  }
};

module.exports = Hashtag;