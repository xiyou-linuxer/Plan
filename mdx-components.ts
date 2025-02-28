import { useMDXComponents as getThemeComponents } from 'nextra-theme-docs'
import { Callout, Cards, Image, ImageZoom } from 'nextra/components'

const themeComponents = getThemeComponents()

export function useMDXComponents(components?: Record<string, React.ComponentType>) {
  return {
    Callout,
    Cards,
    Image,
    ImageZoom,
    ...themeComponents,
    ...components,
  }
}
