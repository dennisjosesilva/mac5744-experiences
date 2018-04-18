#ifndef MATERIAL_HPP_INCLUDED
#define MATERIAL_HPP_INCLUDED

#include <memory>
#include <QObject>

namespace mac5744
{
  class Material : public QObject
  {
  public:
    /* TODO: Finish to code it. */
    Material(
      std::shared_ptr<QVector3D> pemissionColor = std::make_shared<QVector3D>(0.0f, 0.0f, 0.0f),
      std::shared_ptr<QVector3D> pambientColor = std::make_shared<QVector3D(0.2f, 0.2f, 0.2f)
      std::shared_ptr<QVector3D> pdiffuseColor = std::make_shared<QVector3D>(0.8f, 0.8f, 0.8f)
      std::shared_ptr<QVector3D> pspecularColor = std::make_shared<QVector3D>(0.0f, 0.0f, 0.0f),
      float pshininess=12.0);

    inline std::shared_ptr<QVector3D> emissionColor() { return _emissionColor; }
    inline const std::shared_ptr<QVector3D> emissionColor() const { return _emissionColor; }
    inline void emissionColor(std::shared_ptr<QVector3D> pemissionColor) { _emissionColor = pemissionColor; }

    inline std::shared_ptr<QVector3D> ambientColor() { return _ambientColor; }
    inline const std::shared_ptr<QVector3D> ambientColor() const { return _ambientColor; }
    inline void ambientColor(std::shared_ptr<QVector3D> pambientColor) { _ambientColor = pambientColor; }

    inline std::shared_ptr<QVector3D> diffuseColor() { return _diffuseColor; }
    inline const std::shared_ptr<QVector3D> diffuseColor() const { return _diffuseColor; }
    inline void diffuseColor(std::shared_ptr<QVector3D> pdiffuseColor) { _diffuseColor = pdiffuseColor; }

    inline std::shared_ptr<QVector3D> specularColor() { return _specularColor; }
    inline const std::shared_ptr<QVector3D> specularColor() { return _specularColor; }
    inline void specularColor(std::shared_ptr<QVector3D> pspecularColor) { _specularColor = specularColor; }
    
    inline float shininess() { return _shininess; }    
    inline float shininess() const { return _shininess; }
    inline void shininess(float pshininess) { _shininess = shininess; }
    
    static std::unique_ptr<Material> brass();
    static std::unique_ptr<Material> bronze();
    static std::unique_ptr<Material> polishedBronze();
    static std::unique_ptr<Material> chrome();
    static std::unique_ptr<Material> copper();
    static std::unique_ptr<Material> polishedCopper();
    static std::unique_ptr<Material> plasticCyan();
    static std::unique_ptr<Material> emerald();
    static std::unique_ptr<Material> gold();
    static std::unique_ptr<Material> polishedGold();
    static std::unique_ptr<Material> jade();
    static std::unique_ptr<Material> obsidia();
    static std::unique_ptr<Material> pearl();
    static std::unique_ptr<Material> plasticRed();
    static std::unique_ptr<Material> ruby();
    static std::unique_ptr<Material> silver();
    static std::unique_ptr<Material> polishedSilver();
    static std::unique_ptr<Material> tin();
    static std::unique_ptr<Material> turquoise();
    static std::unique_ptr<Material> rubberCyan();
    static std::unique_ptr<Material> rubberWhite();
    static std::unique_ptr<Material> rubberBlack();
    static std::unique_ptr<Material> sun();

  private:  
    std::shared_ptr<QVector3D> _emissionColor;
    std::shared_ptr<QVector3D> _ambientColor;
    std::shared_ptr<QVector3D> _diffuseColor;
    std::shared_ptr<QVector3D> _specularColor;
    float _shininess;
  };
}
#endif